
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> s(n), p(n);

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int i = 0;

    while (i < n) {
        int j = i;
        while (j < n && s[j] == s[i]) {
            j++;
        }
        if (j - i == 1) {
            cout << -1 << '\n';
            return;
        }
        for (int k = i; k < j - 1; k++) {
            p[k] = k + 2;
        }

        p[j - 1] = i + 1;
        i = j;
    }

    for (int x : p) {
        cout << x << " ";
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
