// Interactive edge/cloud prefill-decode scheduler.
//
// Strategy
//   * one remote is picked per request at P PRE time (least loaded)
//   * prefill P PROC is chunked adaptively: full range when the remote has no
//     decode work of its own, otherwise small layer chunks so decode can slip in
//   * every decode step is batched with all currently-ready requests
//   * the local machine prioritises D POST (produces tokens), then interleaves
//     prefill work so TDR does not starve, then D PRE
//   * outstanding prefill uploads are capped so the FIFO uplink is not clogged
//     with huge activation transfers ahead of small decode transfers

#include <bits/stdc++.h>
#if defined(_WIN32) || defined(_WIN64)
  #include <io.h>
  #define OSREAD _read
#else
  #include <unistd.h>
  #define OSREAD read
#endif
using namespace std;

/* ---------------- fast, interaction-safe input ---------------- */
static char rb[1 << 16];
static int rlen = 0, rpos = 0;
static inline int gc() {
    if (rpos >= rlen) {
        int r = (int)OSREAD(0, rb, (unsigned)sizeof(rb));
        if (r <= 0) { rlen = rpos = 0; return -1; }
        rlen = r; rpos = 0;
    }
    return (unsigned char)rb[rpos++];
}
static char tk[160];
static bool readTok() {
    int c = gc();
    while (c == ' ' || c == '\n' || c == '\r' || c == '\t') c = gc();
    if (c < 0) return false;
    int i = 0;
    while (c > 0 && c != ' ' && c != '\n' && c != '\r' && c != '\t') {
        if (i < 159) tk[i++] = (char)c;
        c = gc();
    }
    tk[i] = 0;
    return true;
}
static inline long long RI() { if (!readTok()) exit(0); return strtoll(tk, nullptr, 10); }
static inline double    RD() { if (!readTok()) exit(0); return strtod(tk, nullptr); }

/* ---------------- task-time table ---------------- */
// 0 prefill_pre 1 prefill_proc 2 prefill_post 3 decode_pre 4 decode_proc 5 decode_post
static vector<pair<int, double>> col[6];
static double ipol(int c, double x) {
    auto &v = col[c];
    if (v.empty()) return 1.0;
    if (x <= v.front().first) return v.front().second;
    if (x >= v.back().first)  return v.back().second;
    int lo = 0, hi = (int)v.size() - 1;
    while (hi - lo > 1) { int m = (lo + hi) >> 1; if (v[m].first <= x) lo = m; else hi = m; }
    double x0 = v[lo].first, y0 = v[lo].second, x1 = v[hi].first, y1 = v[hi].second;
    if (x1 <= x0) return y0;
    return y0 + (y1 - y0) * (x - x0) / (x1 - x0);
}

/* ---------------- output buffer ---------------- */
static string ob;
static inline void ai(long long v) {
    char b[24]; int l = 0;
    if (v < 0) { ob.push_back('-'); v = -v; }
    if (!v) b[l++] = '0';
    while (v) { b[l++] = char('0' + (int)(v % 10)); v /= 10; }
    while (l) ob.push_back(b[--l]);
}
static inline void as(const char *s) { ob += s; }

/* ---------------- state ---------------- */
static int K, numLayers;
static double S;

static bool eBusy = false;
static vector<char> cBusy;

static deque<int> pend_ppre, pend_ppost;      // FIFO: oldest first
static vector<deque<int>> pend_pproc;         // per remote: next prefill chunk ready
static vector<int> pend_dpre, pend_dpost;     // batched
static vector<vector<int>> pend_dproc;        // per remote, batched

static vector<int>  q_lin, q_srv, q_nextLs, q_lpp;
static vector<double> q_arr;
static vector<char> q_fin;
static vector<int>  activeCnt, decActive;
static vector<long long> altC;

static int inflightPrefill = 0, outUp = 0, PCAP = 3;
static long long decodeStreak = 0, altE = 0;
static int arrivedCnt = 0, finishedCnt = 0;
static int WAVES = 3;
static double SLO1 = 1e9, SLO2 = 1e9, DIST_BASE = 0.0, W_TP = 0.5, W_C = 0.5;
static double sumTdr = 0.0; static long long nTdr = 0;
static double sumGap = 0.0; static long long nGap = 0;
static vector<double> lastTok;           // last token time per request
static long long decInFlight = 0;        // requests between D PRE and D POST
static double LAT = 0.0, TAU = 0.0, BPT = 1.0;
static double eBusyT = 0.0, upBusyT = 0.0, dnBusyT = 0.0;      // per-transfer latency, ms per token
static double remoteBusy = 0.0;          // total occupied remote time observed
static double t0 = -1.0, tnow = 0.0;

// How many remotes are worth spreading over? Every extra remote represented in
// a decode group costs one more round of link latency in each direction, while
// buying parallel remote compute. Pick the count that minimises the bottleneck.
static long long remoteTasks = 0;
static int chooseUse(int decPop) {
    if (remoteTasks < 4LL * K) return K;   // no measurements yet: spread out
    double m = max(1.0, (double)decPop / WAVES);
    double eT = 2.0 * S + ipol(3, m) + ipol(5, m);
    int best = 1; double bestB = 1e300;
    for (int u = 1; u <= K; u++) {
        double up = u * LAT + m * TAU;
        double rt = S + ipol(4, ceil(m / u));
        double b = max(eT, max(up, rt));
        if (b < bestB - 1e-12) { bestB = b; best = u; }
    }
    // ...but never fewer than the remotes actually needed to absorb the
    // observed workload (prefill included) at a healthy utilisation.
    double el = tnow - t0;
    if (el > 1e-9) {
        int need = (int)ceil(remoteBusy / (0.6 * el));
        if (need > best) best = need;
    }
    if (best < 1) best = 1;
    if (best > K) best = K;
    return best;
}

static void ensureId(int rid) {
    if ((int)q_lin.size() > rid) return;
    size_t ns = rid + 1;
    q_lin.resize(ns, 0); q_srv.resize(ns, 0); q_nextLs.resize(ns, 0);
    q_lpp.resize(ns, 1); q_fin.resize(ns, 0); lastTok.resize(ns, -1.0);
    q_arr.resize(ns, 0.0);
}

static int leastLoaded(int limit) {
    int best = 0;
    for (int k = 1; k < limit; k++) if (activeCnt[k] < activeCnt[best]) best = k;
    return best;
}

int main() {
    K = (int)RI();
    S = RD();
    LAT = RD();                       // latency_in_ms
    double BW = RD();                 // bandwidth_gbps
    BPT = (double)RI();               // bytes_per_token
    TAU = 8.0 * BPT / (BW * 1e6);     // ms of link time per token transferred
    numLayers = (int)RI();
    SLO1 = RD(); SLO2 = RD();
    double tpUB = RD(), tpBase = RD(); (void)tpUB; (void)tpBase;
    DIST_BASE = RD(); W_TP = RD(); W_C = RD();
    // The tests weight throughput anywhere from 0 to 1, so pick the operating
    // point from the weights: fewer, fatter waves when throughput is what
    // scores, more, leaner waves when the waiting-time targets dominate.
    if      (W_TP >= 0.85) WAVES = 5;
    else if (W_TP >= 0.55) WAVES = 2;
    else if (W_TP >= 0.25) WAVES = 3;
    else                   WAVES = 4;

    int N = (int)RI();
    for (int i = 0; i < N; i++) {
        int bs = (int)RI();
        for (int c = 0; c < 6; c++) {
            double v = RD();
            if (v >= 0) col[c].push_back(make_pair(bs, v));
        }
    }
    for (int c = 0; c < 6; c++) sort(col[c].begin(), col[c].end());

    // chunk target: a prefill piece should be about as long as a decode step,
    // but never so short that the per-task schedule cost S dominates.
    double chunkTarget = max(10.0 * S, ipol(4, 16.0));

    cBusy.assign(K, 0);
    pend_pproc.assign(K, deque<int>());
    pend_dproc.assign(K, vector<int>());
    activeCnt.assign(K, 0);
    decActive.assign(K, 0);
    altC.assign(K, 0);
    PCAP = max(8, 4 * K);

    vector<int> tmp;
    ob.reserve(1 << 16);

    while (true) {
        if (!readTok()) return 0;
        if (tk[0] == 'E' && tk[1] == 'N' && tk[2] == 'D') return 0;
        tnow = strtod(tk, nullptr);
        if (t0 < 0) t0 = tnow;
        int e = (int)RI();
        bool sawFin = false;

        for (int ev = 0; ev < e; ev++) {
            if (!readTok()) return 0;
            char h = tk[0];

            if (h == 'A') {                    // ARR <rid> <Lin>
                int rid = (int)RI(); int L = (int)RI();
                ensureId(rid);
                q_lin[rid] = L; q_arr[rid] = tnow;
                arrivedCnt++;
                pend_ppre.push_back(rid);
            } else if (h == 'F') {             // FIN <rid>
                int rid = (int)RI();
                q_fin[rid] = 1; sawFin = true;
                finishedCnt++;
                activeCnt[q_srv[rid]]--;
                decActive[q_srv[rid]]--;
            } else if (h == 'T') {             // TDN <server> <spec> <dur>
                readTok();                     // server (redundant with spec)
                readTok(); char fam = tk[0];   // 'P' or 'D'
                readTok();
                int st;                        // 0 PRE, 1 PROC, 2 POST
                if (tk[1] == 'O') st = 2; else if (tk[2] == 'E') st = 0; else st = 1;

                if (fam == 'P') {
                    if (st == 0) {                       // P PRE
                        RI(); RI(); eBusyT += S + RD();
                        eBusy = false;
                    } else if (st == 1) {                // P PROC <ls> <le> <rm> <rid>
                        RI(); int le = (int)RI(); int rm = (int)RI(); int rid = (int)RI();
                        remoteBusy += S + RD(); remoteTasks++;
                        cBusy[rm] = 0;
                        if (le < numLayers) pend_pproc[rm].push_back(rid);
                    } else {                             // P POST
                        int rm = (int)RI(); int rid = (int)RI(); eBusyT += S + RD();
                        eBusy = false;
                        inflightPrefill--;
                        decActive[rm]++;
                        sumTdr += tnow - q_arr[rid]; nTdr++;
                        pend_dpre.push_back(rid);
                    }
                } else {
                    if (st == 0) {                       // D PRE -1 m rids
                        RI(); int m = (int)RI();
                        for (int j = 0; j < m; j++) RI();
                        eBusyT += S + RD();
                        eBusy = false;
                    } else if (st == 1) {                // D PROC rm m rids
                        int rm = (int)RI(); int m = (int)RI();
                        for (int j = 0; j < m; j++) RI();
                        remoteBusy += S + RD(); remoteTasks++;
                        cBusy[rm] = 0;
                    } else {                             // D POST -1 m rids
                        RI(); int m = (int)RI();
                        tmp.clear();
                        for (int j = 0; j < m; j++) tmp.push_back((int)RI());
                        eBusyT += S + RD();
                        eBusy = false;
                        // FIN for some members may follow later in this frame;
                        // they are filtered out below before D PRE is built.
                        for (size_t j = 0; j < tmp.size(); j++) {
                            int x = tmp[j];
                            if (lastTok[x] >= 0) { sumGap += tnow - lastTok[x]; nGap++; }
                            lastTok[x] = tnow;
                            pend_dpre.push_back(x);
                        }
                    }
                }
            } else {                           // XDN <UP|DOWN> <rm> <size> <PRE|DEC> <m> <rids>
                readTok(); bool up = (tk[0] == 'U');
                int rm = (int)RI();
                double bytes = (double)RI();            // size in bytes
                (up ? upBusyT : dnBusyT) += LAT + (bytes / BPT) * TAU;
                readTok(); bool isPre = (tk[0] == 'P');
                int m = (int)RI();
                for (int j = 0; j < m; j++) {
                    int rid = (int)RI();
                    if (isPre) {
                        if (up) { pend_pproc[rm].push_back(rid); outUp--; }
                        else      pend_ppost.push_back(rid);
                    } else {
                        if (up) pend_dproc[rm].push_back(rid);
                        else    pend_dpost.push_back(rid);
                    }
                }
            }
        }

        /* ------------- decide ------------- */
        if (sawFin) {   // drop finished requests queued by the D POST above
            size_t j = 0;
            for (size_t q = 0; q < pend_dpre.size(); q++) {
                int x = pend_dpre[q];
                if (!q_fin[x]) pend_dpre[j++] = x;
            }
            pend_dpre.resize(j);
        }

        ob.clear();             // assignments are accumulated here first
        int n = 0;

        // A request that sits in none of the pending queues is inside a running
        // task or a transfer, so at least one more frame is guaranteed to come.
        // Only then is it safe to idle the local machine to grow a batch.
        long long pendTotal = (long long)pend_ppre.size() + pend_ppost.size()
                            + pend_dpre.size() + pend_dpost.size();
        for (int k = 0; k < K; k++) pendTotal += pend_pproc[k].size() + pend_dproc[k].size();
        bool canWait = ((long long)arrivedCnt - finishedCnt - pendTotal) > 0;

        // Steer by whichever waiting-time target is actually being missed:
        // dist weights the two normalised excesses equally, so the one that is
        // further out is the one worth spending the local machine on.
        double exTdr = 0.0, exTpot = 0.0;
        if (nTdr) exTdr  = max(0.0, (sumTdr / nTdr - SLO1) / SLO1);
        if (nGap) exTpot = max(0.0, (sumGap / nGap - SLO2) / SLO2);
        int streakLimit = 3, effWaves = WAVES;
        if (W_C > 0.0) {
            if (exTdr > 1.5 * exTpot)  streakLimit = 2;        // arrivals waiting
            else if (exTpot > 1.5 * exTdr) effWaves = WAVES + 1;  // gaps too long
        }

        int decPop = 0;
        for (int k = 0; k < K; k++) decPop += decActive[k];
        size_t dpreTarget = (size_t)max(1, (decPop + effWaves - 1) / effWaves);
        int useK = chooseUse(decPop);

        // Each wave comes back as one downlink transfer per remote, so firing
        // D POST on arrival costs S once per remote. Merging them costs a little
        // token latency and saves most of that overhead.
        // Merging is only worth its latency cost when the local machine, and
        // not the link or the remotes, is the resource we are short of.
        size_t dpostTarget = 1;
        double el2 = tnow - t0;
        if (el2 > 1e-9) {
            double ue = eBusyT / el2;
            if (ue > 0.75 && ue > upBusyT / el2 && ue > dnBusyT / el2) {
    size_t wave = (size_t)max(1, (decPop + effWaves - 1) / effWaves);
                dpostTarget = min(wave, (size_t)max(1LL, decInFlight));
            }
        }

        if (!eBusy) {
            bool hasDPost = !pend_dpost.empty()
                            && (!canWait || pend_dpost.size() >= dpostTarget);
            bool hasDPre  = !pend_dpre.empty() && (!canWait || pend_dpre.size() >= dpreTarget);
            bool hasPPost = !pend_ppost.empty();
            bool hasPPre  = !pend_ppre.empty() && inflightPrefill < PCAP
                            && outUp < (streakLimit < 3 ? 3 : 2);
            bool hasPre   = hasPPost || hasPPre;

            int ch = 0;                        // 1 D POST, 2 prefill, 3 D PRE
            if (hasPre && decodeStreak >= streakLimit) ch = 2;
            else if (hasDPost)                    ch = 1;
            else if (hasPre && hasDPre)           ch = ((altE++) % 2 == 0) ? 2 : 3;
            else if (hasPre)                      ch = 2;
            else if (hasDPre)                     ch = 3;

            if (ch == 1) {
                as("E D POST -1 "); ai((long long)pend_dpost.size());
                for (size_t i = 0; i < pend_dpost.size(); i++) { ob.push_back(' '); ai(pend_dpost[i]); }
                ob.push_back('\n');
                decInFlight -= (long long)pend_dpost.size();
                if (decInFlight < 0) decInFlight = 0;
                pend_dpost.clear();
                eBusy = true; n++; decodeStreak++;
            } else if (ch == 2) {
                if (hasPPost) {
                    int r = pend_ppost.front(); pend_ppost.pop_front();
                    as("E P POST "); ai(q_srv[r]); ob.push_back(' '); ai(r); ob.push_back('\n');
                } else {
                    int r = pend_ppre.front(); pend_ppre.pop_front();
                    int k = leastLoaded(useK);
                    q_srv[r] = k; activeCnt[k]++;
                    q_nextLs[r] = 0;
                    double pp = ipol(1, (double)q_lin[r]);
                    int lpp = numLayers;
                    if (pp > chunkTarget) {
                        lpp = (int)floor((double)numLayers * chunkTarget / pp);
                        if (lpp < 1) lpp = 1;
                        if (lpp > numLayers) lpp = numLayers;
                    }
                    q_lpp[r] = lpp;
                    inflightPrefill++; outUp++;
                    as("E P PRE "); ai(k); ob.push_back(' '); ai(r); ob.push_back('\n');
                }
                eBusy = true; n++; decodeStreak = 0;
            } else if (ch == 3) {
                as("E D PRE -1 "); ai((long long)pend_dpre.size());
                for (size_t i = 0; i < pend_dpre.size(); i++) { ob.push_back(' '); ai(pend_dpre[i]); }
                ob.push_back('\n');
                decInFlight += (long long)pend_dpre.size();
                pend_dpre.clear();
                eBusy = true; n++; decodeStreak++;
            }
        }

        for (int k = 0; k < K; k++) {
            if (cBusy[k]) continue;
            bool hasD = !pend_dproc[k].empty();
            bool hasP = !pend_pproc[k].empty();
            int ch = 0;                        // 1 D PROC, 2 P PROC
            if (hasD && hasP) ch = ((altC[k]++) % 2 == 0) ? 1 : 2;
            else if (hasD)    ch = 1;
            else if (hasP)    ch = 2;

            if (ch == 1) {
                ob.push_back('C'); ai(k); as(" D PROC "); ai(k);
                ob.push_back(' '); ai((long long)pend_dproc[k].size());
                for (size_t i = 0; i < pend_dproc[k].size(); i++) { ob.push_back(' '); ai(pend_dproc[k][i]); }
                ob.push_back('\n');
                pend_dproc[k].clear();
                cBusy[k] = 1; n++;
            } else if (ch == 2) {
                int r = pend_pproc[k].front(); pend_pproc[k].pop_front();
                int ls = q_nextLs[r], le;
                if (decActive[k] == 0) le = numLayers;      // nothing to interleave: run it all
                else {
                    le = ls + q_lpp[r];
                    if (le > numLayers) le = numLayers;
                }
                if (le <= ls) le = ls + 1;
                q_nextLs[r] = le;
                ob.push_back('C'); ai(k); as(" P PROC "); ai(ls); ob.push_back(' '); ai(le);
                ob.push_back(' '); ai(k); ob.push_back(' '); ai(r); ob.push_back('\n');
                cBusy[k] = 1; n++;
            }
        }

        string body;
        body.swap(ob);                          // body now holds the assignments
        ai(n); ob.push_back('\n');
        ob += body;
        fwrite(ob.data(), 1, ob.size(), stdout);
        fflush(stdout);
    }
    return 0;
}