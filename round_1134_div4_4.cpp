#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<bool> used(26, false);

    for (int i = 0; i < n / 2; i++) {
        char a = min(s[i], s[n - i - 1]);
        char b = max(s[i], s[n - i - 1]);

        for (char c = a + 1; c <= b; c++) {
            used[c - 'a'] = true;
        }
    }

    int ans = 0;

    for (int i = 0; i < 26; i++) {
        if (used[i]) {
            ans++;
        }
    }

    cout << ans << "\n";
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