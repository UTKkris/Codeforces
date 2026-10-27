#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n ;
    cin >>n;
    vector<int>a(n);
    for(int i =0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end(),greater<>());
    if (a[0] == a[n - 1])
    {
    cout << "NO\n";
    return;
    }
    else{
        cout << "YES" << "\n";
        for(int i =0;i<n;i++)
        {
            if(i == 1)
            {
                cout << a[n-1] << " ";
                continue;
            }
            if(i == n-1)
            {
                cout << a[1] << " ";
                continue;
            }
            cout << a[i] << " ";
        }
        cout << "\n";
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