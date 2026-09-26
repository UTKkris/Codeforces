#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> freq(101, 0);

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
    }

    int maxFreq = 0;

    for(int x = 1; x <= 100; x++)
    {
        maxFreq = max(maxFreq, freq[x]);
    }

    vector<int> ans;

    // Building frequency layers
    for(int occurrence = 1; occurrence <= maxFreq; occurrence++)
    {
        // Larger values first 
        for(int x = 100; x >= 1; x--)
        {
            if(freq[x] >= occurrence)
            {
                ans.push_back(x);
            }
        }
    }

    for(int x : ans)
    {
        cout << x << " ";
    }

    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}