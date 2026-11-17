#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> first, extra, last;

    for (int i = 0; i < n; ) {
        int j = i;

        while (j < n && a[i] == a[j]) {
            j++;
        }

        int freq = j - i;

        
        first.push_back(a[i]);

        
        if (freq > 1) {
            last.push_back(a[i]);
        }

        
        for (int k = 2; k < freq; k++) {
            extra.push_back(a[i]);
        }

        i = j;
    }

    reverse(last.begin(), last.end());

    cout << first.size() + last.size() << "\n";

    for (int x : first) cout << x << " ";
    for (int x : extra) cout << x << " ";
    for (int x : last) cout << x << " ";

    cout << "\n";
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