#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    if(k != 4)
    {
        int ans = INT_MAX;

        for(int i = 0; i < n; i++)
        {
            if(arr[i] % k == 0)
            {
                cout << 0 << '\n';
                return;
            }

            ans = min(ans, k - (arr[i] % k));
        }

        cout << ans << '\n';
        return;
    }

    // k == 4
    int even = 0;
    int ans = INT_MAX;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] % 4 == 0)
        {
            cout << 0 << '\n';
            return;
        }

        if(arr[i] % 2 == 0)
            even++;

        ans = min(ans, 4 - (arr[i] % 4));
    }

    if(even >= 2)
        cout << 0 << '\n';
    else if(even == 1)
        cout << min(1, ans) << '\n';
    else
        cout << min(2, ans) << '\n';
}

int main(){
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