#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    int k;
    cin >> n >> k;
    string s;
    cin >> s;
    int count = 0;
    //initial window check--->No. of white cells
    for(int i = 0;i<k;i++){
        if(s[i] == 'W'){
            count++;
        }
    }
    int ans = count;
    //now we slide the window....
    for(int i =k;i<n;i++){
        if(s[i-k] == 'W'){
            count--;
        }
        if(s[i] == 'W'){
            count++;
        }
        ans = min(ans,count);
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}