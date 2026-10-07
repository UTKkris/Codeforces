/*#include<bits/stdc++.h>
#include<iostream>

using namespace std;

void solve()
{
    int n;
    cin >>n;
    vector<int>b(n);
    for(int i =0;i<n;i++)
    {
        cin >> b[i];
    }
    cout << b[0];
    for(int i = 0; i < n - 1; i++)
    {
        cout << b[i + 1];

        if(b[i] > b[i + 1])
        {
            cout << b[i + 1];
        }
    }
    cout << "\n";
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
*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> b(n);
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<int> ans;

    ans.push_back(b[0]);

    for(int i = 1; i < n; i++)
    {
        if(b[i] < b[i - 1])
        {
            ans.push_back(b[i]);
        }

        ans.push_back(b[i]);
    }

    cout << ans.size() << "\n";

    for(int x : ans)
    {
        cout << x << " ";
    }

    cout << "\n";
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