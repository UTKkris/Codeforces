#include<bits/stdc++.h>
#include<iostream>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i =0;i<n;i++)
    {
        cin >> arr[i];
    }
    int finMin=INT_MAX;
    for(int i=0;i<n;i++)
    {
        finMin = min(finMin,abs(arr[i]));
    }
    cout << finMin << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}