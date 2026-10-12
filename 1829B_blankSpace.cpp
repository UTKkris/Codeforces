
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int maxCount = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            count++;
            maxCount = max(maxCount, count);
        } else {
            count = 0;
        }
    }

    cout << maxCount << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
