#include<bits/stdc++.h>

using namespace std;

// void solve()
// {
//     int n ;
//     int k;
//     int x;
//     cin >> n >> k >> x;
//     int sum = 0;
//     vector<int>ans;
//        while(sum<=n){
//         if(k == 0)
//         {
//             break;
//         }
//         else if(k == x)
//         {
//             k--;
//             continue;
//         }
//         if(sum == n)
//         {
//             break;
//         }
//         if(sum+k <= n)
//         {
//             ans.push_back(k);
//             sum+=k;
//         }
//         else{
//             k--;
//         }
//     }
//     int finSum = 0;
//     for(int i =0;i<ans.size();i++)
//     {
//         finSum += ans[i];
//     }
//     if(finSum == n)
//     {
//         cout << "Yes" << "\n";
//         cout << ans.size() << "\n";
//         for(int i =0;i<ans.size();i++){
//             cout << ans[i] << " ";
//         }
//         cout << "\n";
//     }
//     else{
//         cout << "No" << "\n";
//     }
// }

void solve() {
    int n, k, x;
    cin >> n >> k >> x;

    if (x != 1) {
        cout << "YES\n";
        cout << n << "\n";
        for (int i = 0; i < n; i++) {
            cout << 1 << " ";
        }
        cout << "\n";
    }
    else if (k >= 2 && n % 2 == 0) {
        cout << "YES\n";
        cout << n / 2 << "\n";
        for (int i = 0; i < n / 2; i++) {
            cout << 2 << " ";
        }
        cout << "\n";
    }
    else if (k >= 3 && n % 2 == 1) {
        cout << "YES\n";
        cout << 1 + (n - 3) / 2 << "\n";

        cout << 3 << " ";
        for (int i = 0; i < (n - 3) / 2; i++) {
            cout << 2 << " ";
        }
        cout << "\n";
    }
    else {
        cout << "NO\n";
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