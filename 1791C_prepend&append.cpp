#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int left = 0;
    int right = n-1;
    while(left<right)
    {
        if((s[left] - '0' == 0 && s[right]-'0' == 1) || (s[left]-'0' == 1 && s[right]-'0' == 0)){
            left++;
            right--;
        }
        else{
            break;
        }
    }
    if((left > right))
    {
        cout << 0 << "\n";
    }
    else{
        cout << right-left+1 << "\n";
    }
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