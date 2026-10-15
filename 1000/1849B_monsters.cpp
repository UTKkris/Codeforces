/* My code written is not optimal...it runs in O(nA) where A is the no. of attacks*/

#include<bits/stdc++.h>

using namespace std;

// int currMaxi(vector<int> &a)
// {
//     int m = a.size();
//     int maxi = INT_MIN;
//     int maxIndex = 0;
//     for(int i =0;i<m;i++)
//     {
//         if(a[i] > maxi)
//         {
//             maxi = a[i];
//             maxIndex = i;
//         }
//         else if(a[i] == maxi)
//         {
//             continue;
//         }
//         else{
//             continue;
//         }
//     }
//     return maxIndex;
// }
// void solve()
// {
//     int n;
//     int k;
//     cin >> n >> k;
//     vector<int>a(n);
//     for(int i =0;i<n;i++)
//     {
//         cin >> a[i];
//     }
//     vector<int>finOrder;
//     int idx = 0;
//     while (count_if(a.begin(), a.end(), [](int x) {
//          return x > 0;
//     }) > 0) {
//             idx = currMaxi(a);
//             a[idx] = a[idx] - k;
//             if(a[idx] <= 0)
//             {
//                 finOrder.push_back(idx+1);
//             }
//             else{
//                 continue;
//             }
//     }
//     for(int i =0;i<finOrder.size();i++)
//     {
//         cout << finOrder[i] << " ";
//     }
//     cout << "\n";
// }

void solve(){
    int n;
    int k;
    cin >> n >> k;
    vector<int>a(n);
    for(int i =0;i<n;i++)
    {
        cin >> a[i];
    }
    vector<pair<int,int>>remainder;
    int rem = 0;
    for(int i =0;i<n;i++)
    {    
        rem = a[i]%k;
        if(rem == 0)
        {
            rem = k;
        }
        remainder.push_back({rem,i+1});
    }
    sort(remainder.begin(),remainder.end(),[](auto &a, auto &b){
        if(a.first != b.first)
        {
            return a.first > b.first;
        }
        else{
            return a.second < b.second;
        }
    });
    for(int i =0;i<n;i++)
    {
        cout << remainder[i].second << " ";
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