#include<bits/stdc++.h>
#include<iostream>

using namespace std;

void solve(){
    int n ;
    cin >>n;
    vector<int>a(n);
    for(int i =0;i<n;i++)
    {
        cin >> a[i];
    }
    int oddCount = 0;
    int evenCount = 0;
    for(int i =0;i<n;i++)
    {
        if(a[i]%2 == 0)
        {
            evenCount++;
        }
        else if(a[i] %2 !=0)
        {
            oddCount++;
        }
    }
    if(oddCount%2 != 0)
    {
        cout << "No" << "\n";
    }
    else if(oddCount%2 == 0)
    {
        cout << "Yes" << "\n";
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