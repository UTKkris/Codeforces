#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int b = 1;
    int d =0;
    for(int i=1;i*i <= n;i++){
        if(n%i == 0)
        {
            b = max(b,i);
            d = n/i;
            if(i > 1){
                b = max(b,d);
            }
        }
    }
    cout << n-b << " " << b << "\n";
}
// void solve(){
//     int n;
//     cin >> n;
//     int a;
//     int b;
//     int minLcm = INT_MAX;
//     for(int i = 1;i<=(n/2);i++)
//     {
//         a = n-i;
//         b = i;
//         if(a >=b && a%b == 0)
//         {
//             minLcm = min(minLcm,a);
//         }
//         // else if(a < b && b%a == 0)
//         // {
//         //     minLcm = min(minLcm,b);
//         // } 
//     }
//     cout << minLcm << " " << n-(minLcm) << "\n";
// }

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