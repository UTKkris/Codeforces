#include<bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    int mindiff=INT_MAX;
    for(int i = 0; i < n-1; i++)
    {
        if(a[i] > a[i+1])
        {
            cout << 0 << "\n";
            return;
        }

        mindiff = min(mindiff, a[i+1] - a[i]);
    }
    cout << mindiff / 2 + 1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}