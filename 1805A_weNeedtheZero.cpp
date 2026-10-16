#include<bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int>a(n);
    int XoR = 0;
    for(int i =0;i<n;i++)
    {
        cin >> a[i];
        XoR = XoR ^ a[i];
    }
    if(n%2 == 0)
    {
        if(XoR != 0)
        {
            cout << -1 << "\n";
            return;
        }
        else{
            cout << 0 << "\n";
        }
    }
    else if(n%2 !=0)
    {
        cout << (XoR ^ 0) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t ;
    cin >>t;
    while(t--)
    {
        solve();
    }
    return 0;
}