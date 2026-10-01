#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    int currlength = 1;
    int maxlength = 1;
    for(int i =0;i<n-1;i++)
    {
        if(arr[i+1]>arr[i])
        {
            currlength++;
            maxlength = max(maxlength,currlength);
        }
        if(arr[i+1] <= arr[i])
        {
            currlength=1;
        }
    }
    cout << maxlength << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}