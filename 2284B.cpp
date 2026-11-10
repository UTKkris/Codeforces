#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long sum = 0;

    for (int i = n - k; i < n; i++) {
        sum += a[i];
    }

    if (k == n) {
        cout << "YES\n";
        for (auto x : a) cout << x << " ";
        cout << "\n";
        return;
    }


    if (a[n - k - 1] * k >= sum) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    for (int i = n - k; i < n; i++) {
        cout << a[i] << " ";
    }

    for (int i = n - k - 1; i >= 0; i--) {
        cout << a[i] << " ";
    }

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