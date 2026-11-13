#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long w, h;
    cin >> w >> h;

    int k1;
    cin >> k1;
    vector<long long> hs1(k1);
    for(int i = 0; i < k1; i++){
        cin >> hs1[i];
    }

    int k2;
    cin >> k2;
    vector<long long> hs2(k2);
    for(int i = 0; i < k2; i++){
        cin >> hs2[i];
    }

    int k3;
    cin >> k3;
    vector<long long> vs1(k3);
    for(int i = 0; i < k3; i++){
        cin >> vs1[i];
    }

    int k4;
    cin >> k4;
    vector<long long> vs2(k4);
    for(int i = 0; i < k4; i++){
        cin >> vs2[i];
    }

    long long A1 = (vs1[k3-1] - vs1[0]) * w;
    long long A2 = (vs2[k4-1] - vs2[0]) * w;
    long long A3 = (hs1[k1-1] - hs1[0]) * h;
    long long A4 = (hs2[k2-1] - hs2[0]) * h;

    long long finalArea = max({A1, A2, A3, A4});

    cout << finalArea << "\n";
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