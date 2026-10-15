
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> a(n);

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;

        a[i].resize(m);

        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<pair<int, int>> mpp;

    for (int i = 0; i < n; i++)
    {
        int min1 = *min_element(a[i].begin(), a[i].end());

        auto it = find(a[i].begin(), a[i].end(), min1);
        a[i].erase(it);

        int min2 = *min_element(a[i].begin(), a[i].end());

        mpp.push_back({min1, min2});
    }

    sort(mpp.begin(), mpp.end(), [](auto &a, auto &b) {
        return a.second < b.second;
    });

    long long sum = 0;
    long long globalMin = LLONG_MAX;

    for (auto p : mpp)
    {
        globalMin = min(globalMin, (long long)p.first);
        sum += p.second;
    }

    long long ans = globalMin + sum - mpp[0].second;

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
