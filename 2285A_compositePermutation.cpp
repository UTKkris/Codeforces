
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    if (n < 4) {
        cout << -1 << '\n';
        return;
    }

    cout << "4 2 3 1 ";

    for (int i = 5; i <= n; i++) {
        cout << i << " ";
    }

    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
