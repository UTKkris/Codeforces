#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    int x;
    cin >> n >> x;
    vector<int>a(n);
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    int Lnew = a[0] - x;
    int Rnew = a[0] + x;
    int count = 0;
    for(int i =1;i<n;i++){
        Lnew = max(Lnew,a[i]-x);
        Rnew = min(Rnew,a[i]+x);
        if(Lnew > Rnew){
            count++;
            Lnew = a[i]-x;
            Rnew = a[i]+x;
        }
        else{
            continue;
        }
        
    }
    cout << count << "\n";
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