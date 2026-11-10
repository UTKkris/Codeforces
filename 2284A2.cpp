#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    long long base = 0, height = 0;

    for (int i = 0; i < n; i++) {
        long long val = (1LL << a[i]);

        if (base <= height) {
            base += val;
        } else {
            height += val;
        }
    }

    cout << base * height << '\n';
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