#include<bits/stdc++.h>
#include<iostream>

using namespace std;

void solve()
{
    int n;
    int m;
    cin >> n >> m;
    string x;
    string s;
    cin >> x;
    cin >> s;
    int count = 0;

    while(x.length() < s.length())
    {
        x += x;
        count++;
    }

    if(x.find(s) != string::npos)
    {
        cout << count << "\n";
    }
    else
    {
        x += x;
        count++;

        if(x.find(s) != string::npos)
            cout << count << "\n";
        else
            cout << -1 << "\n";
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