
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long currCount = 0;
    long long noWays = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] <= q)
        {
            currCount++;
        }
        else
        {
            if (currCount >= k)
            {
                long long x = currCount - k + 1;
                noWays += x * (x + 1) / 2;
            }

            currCount = 0;
        }
    }
    
    if (currCount >= k)
    {
        long long x = currCount - k + 1;
        noWays += x * (x + 1) / 2;
    }

    cout << noWays << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
