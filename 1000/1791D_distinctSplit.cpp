#include<bits/stdc++.h>

using namespace std;

// int count(string s)
// {
//     unordered_set<char> element;

//     for (char it : s)
//     {
//         if (element.find(it) == element.end())
//         {
//             element.insert(it);
//         }
//     }

//     return element.size();
// }

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int>prefix(n),suffix(n);
    vector<int>freq(26,0);
    int distinct =0;
    for(int i =0;i<n;i++)
    {
        if(freq[s[i]-'a'] ==0)
        {
            distinct++;
        }
        freq[s[i]-'a']++;
        prefix[i] = distinct;
    }
    fill(freq.begin(),freq.end(),0);
    distinct = 0;
    for(int i =n-1;i>=0;i--)
    {
        if(freq[s[i]-'a'] == 0)
        {
            distinct++;
        }
        freq[s[i]-'a']++;
        suffix[i] = distinct;
    }
    int maxCount = 0;

    for(int i =0;i<n-1;i++)
    {
        maxCount = max(maxCount,prefix[i]+suffix[i+1]);
    }
    cout << maxCount << "\n";
}
// void solve(){
//     int n;
//     cin >> n;
//     string s;
//     cin >> s;
//     string slice1;
//     string slice2;
//     int cnt1 = 0;
//     int cnt2 = 0;
//     int maxCount = INT_MIN;
//     for(int i =0;i< n;i++)
//     {
//         slice1 = s.substr(0,i+1);
//         cnt1 = count(slice1);
//         slice2 = s.substr(i+1,n-i-1);
//         cnt2 = count(slice2);
//         maxCount = max(maxCount,cnt1+cnt2);
//     }
//     cout << maxCount << "\n";
// }

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