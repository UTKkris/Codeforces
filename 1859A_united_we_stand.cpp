#include<bits/stdc++.h>
#include<iostream>

using namespace std;

// void solve(){
//     int n;
//     cin >>n;
//     vector<int>a(n);
//     for(int i =0;i<n;i++)
//     {
//         cin >> a[i];
//     }
//     int lb = 0;
//     int lc = 0;
//     vector<int>b;
//     vector<int>c;
//     for(int i =0;i<n;i++)
//     {
//         if(a[i] % 2 !=0)
//         {
//             b.push_back(a[i]);
//             lb++;
//         }
//         else if(a[i] %2 == 0)
//         {
//             c.push_back(a[i]);
//             lc++;
//         }
//     }
//     if(b.empty() || c.empty())
//     {
//         cout << -1 << "\n";
//         return;
//     }
//     cout << lb << "\n" << lc << "\n";
//     for(int i =0;i<lb;i++)
//     {
//         cout << b[i] << " ";
//     }
//     cout << "\n";
//     for(int i =0;i<lc;i++)
//     {
//         cout << c[i] << " ";
//     } 
//     cout << "\n";
// }
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i =0;i<n;i++)
    {
        cin >> a[i];
    }
    int mx = *max_element(a.begin(),a.end());
    vector<int>b;
    vector<int>c;
    for(int i =0;i<n;i++)
    {
        if(a[i] == mx)
        {
            c.push_back(a[i]);
        }
        else
        {
            b.push_back(a[i]);
        }
    }
    if(b.empty() || c.empty())
    {
        cout << -1 << "\n";
        return;
    }
    cout << b.size() << " " << c.size() << "\n";

    for(int i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }
    cout << "\n";

    for(int i = 0; i < c.size(); i++)
    {
        cout << c[i] << " ";
    }
    cout << "\n";
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