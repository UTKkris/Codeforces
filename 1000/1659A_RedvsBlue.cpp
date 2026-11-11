#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    int r;
    int b;
    cin >> n >> r >> b;
    int q = r/(b+1);
    int rem = r%(b+1);
    for(int i = 0; i <= b; i++){
    int cnt = q;
    if(i < rem) cnt++;
    while(cnt > 0){
        cout << 'R';
        cnt--;
    }
    if(i < b) cout << 'B';
}
    cout << "\n";
    /*WRONG APPROACH*/
    // int together = 0;
    //    if(r > ceil(n/2.0)){
    //     together = (r-ceil(n/2.0))+1;
    //     while(b>0){
    //         while(together > 0){
    //             cout << 'R';
    //             together--;
    //             r--;
    //         }
    //         cout << 'B';
    //         b--;
    //         cout << 'R';
    //         r--;
    //     }
    //     if(b==0 && r!=0){
    //         while(r>0){
    //             cout << 'R';
    //             r--;
    //         }
    //     }
    //     cout << "\n";
    //     return;
    // }
    // else if(r == ceil(n/2.0)){
    //     while(r>0){
    //         cout << 'R';
    //         r--;
    //         if(b>0){
    //             cout << 'B';
    //             b--; 
    //         }
    //     }
    //     cout << "\n";
    //     return;
    // }
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