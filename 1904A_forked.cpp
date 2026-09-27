#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void solve(){
    int a;
    int b;
    long long xk,yk;
    long long xq,yq;
    cin >>a>>b;
    cin >>xk>>yk;
    cin >>xq>>yq;
    vector<pair<long long, long long>>moves = {
            {a,b},{a,-b},{-a,b},{-a,-b},{b,a},{b,-a},{-b,a},{-b,-a}
    };
    set<pair<long long,long long>>kingAttack;
    for(auto move : moves)
    {
        long long kx = xk + move.first;
        long long ky = yk + move.second;
        kingAttack.insert({kx,ky});
    }
    set<pair<long long, long long>>bothAttack;
    for(auto move : moves)
    {
        long long kx = xq + move.first;
        long long ky = yq + move.second;
        if(kingAttack.count({kx,ky})){
            bothAttack.insert({kx,ky});
        }
    }
    cout << bothAttack.size() << "\n";
}

int main()
{
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