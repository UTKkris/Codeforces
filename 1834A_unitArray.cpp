
#include <bits/stdc++.h>
#include<iostream>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    int neg = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (x == -1)
            neg++;
    }

    int ans = 0;

    while (neg > n - neg || neg % 2 != 0)
    {
        neg--;
        ans++;
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
