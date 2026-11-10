#include <bits/stdc++.h>
using namespace std;

const int MAXA = 200000;

vector<bool> isPrime(MAXA + 1, true);

void sieve() {
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= MAXA; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAXA; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {

        if (isPrime[a[i]]) {
            continue;
        }

        for (int p = a[i] + 1; p <= MAXA; p++) {
            if (isPrime[p]) {
                a[i] = p;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}