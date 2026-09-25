#include<iostream>
#include<string>
#include<bits/stdc++.h>

using namespace std;

void solve(){
    char c;
    int n;
    string s;
    cin >> n; 
    cin >> c;
    cin >> s;
    int minCoins=0;
    for(int i =0;i<(n/2);i++)
    {
        if(s[i]==s[n-(i+1)])
        {
            continue;
        }
        else if(s[i] == c && s[n-(i+1)] != c){
            s[n-(i+1)] = c;
            minCoins++;
            continue;
        }
        else if(s[n-(i+1)] == c && s[i]!=c)
        {
            s[i] = c;
            minCoins++;
            continue;
        }
        else{
            s[i] = c;
            s[n-(i+1)] = c;
            minCoins = minCoins + 2;
            continue;
        }
    }
    cout << minCoins << "\n";
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