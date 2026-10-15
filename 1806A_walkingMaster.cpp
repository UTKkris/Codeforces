#include<bits/stdc++.h>

using namespace std;

void solve(){
    long long a,b,c,d;
    cin >> a >> b >> c >> d;
    if(d < b || (a + (d - b) < c))
    {
        cout << -1 << "\n";
    }
    else{
        cout << (d-b)+(a+(d-b)-c) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}