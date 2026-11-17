#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    long long minimumTime = 0;
    vector<pair<int,int>>v;
    for(int i =0;i<n;i++){
        v.push_back({a[i],i+1});
    }
    sort(v.rbegin(),v.rend());
    for(int i =0;i<n;i++){
        minimumTime += 2LL * (i/2 + 1) * v[i].first;
    }
    vector<int> optimal(n + 1);
    optimal[0] = 0; 
    for(int i =0;i<n;i++){
        optimal[v[i].second] = (i%2==0) ? (i/2+1) : -(i/2+1);
    }
    cout << minimumTime << "\n";
    for(int i =0;i<=n;i++){
        cout << optimal[i] << " ";
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