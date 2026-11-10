#include<bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    if(c == 'g'){
        cout << 0 << "\n";
        return;
    }
    s+=s;
    int nextG = -1;
    int ans = 0;
    for(int i = 2*(n-1);i>=0;i--){
        if(s[i] == 'g')
        {
            nextG = i;
        }
        if(i < n && s[i]==c)
        {
            ans= max(ans,nextG-i);
        }
    }
    cout << ans << "\n";
        /*THIS METHOD GIVES TLE*/
    // int firstG =0;
    // int confirmCross = 0;
    // for(int i =0;i<n;i++)
    // {
    //     if(s[i]=='g')
    //     {
    //         firstG = i;
    //         break;
    //     }
    // }
    // for(int i =0;i<n;i++)
    // {
    //     bool flag = false;
    //     if(s[i] == c){
    //         for(int j =i;j<n;j++)
    //         {
    //             if(s[j] == 'g')
    //             {
    //                 flag = true;
    //                 confirmCross = max(confirmCross,j-i);
    //                 break;
    //             }
    //         }
    //         if(flag == false){
    //             confirmCross = max(confirmCross  , n-i+firstG);
    //         }
    //     }
    // }
    // cout << confirmCross << "\n";
}

int main(){
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