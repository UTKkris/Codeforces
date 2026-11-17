#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int countSwitch = 0;

    if (s[0] == 'B') {
        countSwitch++;
    }

    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            countSwitch++;
        }
    }

    cout << countSwitch << "\n";
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