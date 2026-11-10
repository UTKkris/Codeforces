#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    long long D;
    cin >> N >> D;

    vector<long long> p(N);

    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }

    int left = 0;
    int right = N - 1;
    int count = 0;
    int more = 0;

    sort(p.begin(), p.end());

    while (left <= right) {

        if (p[right] * (more + 1) > D) {
            count++;
            right--;
            more = 0;
        }
        else {
            if (left == right) {
                break;
            }

            more++;
            left++;
        }
    }

    cout << count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}