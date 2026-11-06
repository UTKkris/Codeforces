#include<bits/stdc++.h>

using namespace std;

void solve(){
    long long n,k,b,s;
    cin >> n >> k >> b >> s;
    long long quotientSatisfy = k*b;
    long long rem = s-quotientSatisfy;
    if(rem < 0 || rem > n*(k-1)){
        cout << -1 << "\n";
        return;
    }
    vector<long long>a(n,0);
    a[0] = quotientSatisfy + min(rem,k-1);
    rem-=min(rem,k-1);
    for(int i = 1;i<n && rem > 0;i++){
        long long add = min(rem,k-1);
        a[i] = add;
        rem-=add;
    }
    for(int i =0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << "\n";
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