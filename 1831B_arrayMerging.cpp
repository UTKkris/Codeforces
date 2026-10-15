#include<bits/stdc++.h>

using namespace std;

//WRONG UNDERSTANDING OF THE QUESTION

// void solve(){
//     int n;
//     cin >>n;
//     vector<int>a(n);
//     for(int i =0;i<n;i++)
//     {
//         cin >> a[i];
//     }
//     vector<int>b(n);
//     for(int i =0;i<n;i++)
//     {
//         cin >> b[i];
//     }
//     int currCount = 1;
//     int maxCount = 0;
//     int currRead = 0;
//     for(int i =0;i<n-1;i++)
//     {
//         if(a[i] == a[i+1])
//         {
//             currRead = a[i];
//             currCount++;
//             maxCount = max(maxCount,currCount);
//         }
//         else{
//             currCount = 1;
//         }
//         if(a[n-1] != a[n-2])
//         {
//             currRead = a[n-1];
//             currCount = 1;
//         }
//     }
//     if(currRead != b[0])
//     {
//         currCount = 1;
//     }
//     for(int i=0;i<n;i++)
//     {
//         if(b[i] == b[i+1])
//         {
//             currRead = b[i];
//             currCount++;
//             maxCount = max(maxCount,currCount);
//         }
//         else{
//             currCount = 1;
//         }
//     }
//     cout << maxCount << "\n";
// }

void solve(){
    int n;
    cin >>n;
    vector<int>a(n);
    for(int i =0;i<n;i++)
    {
        cin >> a[i];
    }
    vector<int>b(n);
    for(int i =0;i<n;i++)
    {
        cin >> b[i];
    }
    unordered_map<int,int>conseCountA,conseCountB;
    int count = 1;
    for(int i =1;i<n;i++){
        if(a[i] == a[i-1])
        {
            count++;
        }
        else{
            conseCountA[a[i-1]] = max(conseCountA[a[i-1]],count);
            count = 1;
        }
    }
    conseCountA[a[n-1]] = max(conseCountA[a[n-1]],count);
    count =1;
    for(int i =1;i<n;i++){
        if(b[i] == b[i-1])
        {
            count++;
        }
        else{
            conseCountB[b[i-1]] = max(conseCountB[b[i-1]],count);
            count = 1;
        }
    }
    conseCountB[b[n-1]] = max(conseCountB[b[n-1]],count);
    int ans = INT_MIN;
    for(auto [x,freq] : conseCountA)
    {
        ans = max(ans,freq + conseCountB[x]);
    }
    for(auto [x,freq] : conseCountB)
    {
        ans = max(ans, freq + conseCountA[x]);
    }
    cout << ans << "\n";
}
int main(){
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