
#include <iostream>
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    if (a == n && b == n) {
        cout << "YES\n";
    }
    else if (a + b <= n - 2) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
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
