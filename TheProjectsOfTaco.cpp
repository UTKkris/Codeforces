#include<bits/stdc++.h>

using namespace std;

void solve()
{
    int n ;
    cin >> n;
    vector<int>a(n);
    int sum =0;
    int maxi = INT_MIN;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    if(n ==1)
    {
        cout << a[0] << "\n";
        return;
    }
    else{
        for(int i =0;i<n;i++)
        {
            maxi = max(maxi,a[i]);
            sum += a[i];
        }
    }
    int ans = sum-(2*maxi);
    if(ans <= 0)
    {
        cout << ans << "\n";
        return;
    }
    if(ans > 0)
    {
        cout << -ans << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >>t;
    while(t--)
    {
        solve();
    }
    return 0;
}