#include<bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    int k;
    cin >> n >> k;
    vector<int>arr(n);
    for(int i =0;i<n;i++)
    {
        cin >> arr[i];
    }
    bool flag = false;
    for(int i =0;i<n;i++)
    {
        if(arr[i] == k)
        {
            cout << "YES" << "\n";
            flag = true;
            break;
        }
    }
    if(flag == false)
    {
        cout << "NO" << "\n";
    }
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