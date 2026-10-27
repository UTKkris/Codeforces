#include<bits/stdc++.h>

using namespace std;

/* THIS METHOD GIVE TLE :/ */
// void solve(){
//     int n;
//     cin >> n;
//     vector<int>a(n);
//     for(int i=0;i<n;i++)
//     {
//         cin >> a[i];
//     }
//     int inProduct = 1;
//     int finProduct = 1;
//     int ans = 0;
//     bool found = false;
//     for(int i =0;i<n;i++)
//     {
//         inProduct*=a[i];
//         for(int j =n-1;j>i;i--)
//         {
//             finProduct *=a[j];
//         }
//         if(inProduct == finProduct)
//         {
//             found = true;
//             ans = i;
//             break;
//         }
//     }
//     if(found){
//     cout  << ans << "\n";}
//     else{
//         cout << -1 << "\n";
//     }
// }

void solve()
{
    int n;
    cin >> n;
    vector<int>a(n);
    int count = 0;
    int currCount = 0;
    int ans = 0;
    for(int i =0;i<n;i++)
    {
        cin >> a[i];
        if(a[i] == 2)
        {
            count++;
        }
    }
    if(count%2!=0)
    {
        cout << -1 << "\n";
        return;
    }
    if(count == 0)
    {
        cout << 1 << "\n";
        return;
    }
    else{
        for(int i = 0;i<n;i++)
        {
            if(currCount == count/2)
            {
                ans = i;
                break;
            }
            if(a[i] == 2)
            {
                currCount++;
            }
        }
    }
    cout << ans << "\n";
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