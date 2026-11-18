#include<bits/stdc++.h>

using namespace std;

int xorUpto(int n) {
    if(n % 4 == 0) return n;
    if(n % 4 == 1) return 1;
    if(n % 4 == 2) return n + 1;
    return 0;
}

void solve(){
    int a;
    int b;
    cin >> a >> b;
    int resxor = 0;
    resxor = xorUpto(a - 1);
    int c = resxor ^ b;
    if(c == 0){
        cout << a << "\n";
    }
    else if(c == a){
        cout << a+2 << "\n";
    }  
    else{
        cout << a+1 << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >>t;
    while(t--){
        solve();
    }
    return 0;
}