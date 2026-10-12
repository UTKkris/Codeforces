#include<bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n; 
    vector<int>a(n);
    for(int i =0;i<n;i++)
    {
        cin >> a[i];
    }
    vector<int>ans;
    for(int i =0;i<n;i++)
    {
        ans.push_back(n-a[i]+1);
    }
    for(int i =0;i<n;i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main(){
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