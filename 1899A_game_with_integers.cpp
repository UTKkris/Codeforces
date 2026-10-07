#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    if(n%3 == 1 || n%3==2)
    {
        cout << "First" << "\n";
    }
    else if(n%3 == 0 )
    {
        cout << "Second" << "\n";
    }
}

int main()
{
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