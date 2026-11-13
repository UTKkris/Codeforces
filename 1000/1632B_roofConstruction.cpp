
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int x = 1;

    while (x * 2 < n) {
        x *= 2;
    }

    // First group: descending
    for (int i = x - 1; i >= 0; i--) {
        cout << i << " ";
    }

    // Second group: ascending
    for (int i = x; i < n; i++) {
        cout << i << " ";
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
