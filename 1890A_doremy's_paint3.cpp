#include<bits/stdc++.h>
#include<iostream>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    int count = 1;
    int inCount = 0;
    int distinct = 1;

    for(int i = 0; i < n - 1; i++)
    {
        if(arr[i] == arr[i + 1])
        {
            count++;
        }
        else
        {
            distinct++;
            inCount = count;
            count = 1;
        }
    }

    if(distinct == 1)
    {
        cout << "YES\n";
    }
    else if(distinct == 2 && abs(inCount - count) <= 1)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}