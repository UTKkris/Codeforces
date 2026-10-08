#include<bits/stdc++.h>
#include<iostream>

using namespace std;

void solve()
{
    int a;
    int b;
    int c;
    cin >> a >> b >> c;
    if(a > b)
    {
        cout << "First" << "\n";
        return;
    }
    if(b > a)
    {
        cout << "Second" << "\n";
        return;
    }
    else if(a==b && c%2 ==0)
    {
        cout << "Second" << "\n";
        return;
    }
    else if(a == b && c%2 != 0)
    {
        cout << "First" << "\n";
        return;
    } 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t ;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}