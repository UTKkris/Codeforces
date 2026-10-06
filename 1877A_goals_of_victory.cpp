#include<bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int>arr(n-1);
    for(int i =0;i<n-1;i++)
    {
        cin >> arr[i];
    }
    int sum = 0;
    for(int i =0;i<n-1;i++)
    {
        sum = sum + arr[i];
    }
    cout << (-sum) << "\n";
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