#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void solve(){

    int n,x;
    cin >> n >> x;
    vector<int>a(n);
    for(int i =0;i<n;i++)
    {
        cin >> a[i];
    }
    //assuming some quantity of fuel y
    //y should be the max(a0,a1-a0,a2-a1.....an-1-an-2, 2(x-an-1))
    int y = a[0];
    for(int i =1;i<n;i++)
    {
        y=max(y,(a[i]-a[i-1]));
    }
    y = max(y,2*(x-a[n-1]));
    cout << y << "\n";
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