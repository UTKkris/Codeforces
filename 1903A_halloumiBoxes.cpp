#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    int k;
    cin >> n >> k;
    bool flag = true;
    vector<int>a(n);
    for(int i =0;i<n;i++)
    {
        cin >> a[i];
        if(i>=1){
            if(a[i] < a[i-1]){
                flag = false;
            }
        }
    }
    if(k ==1 && flag == false)
    {
        cout << "NO" << "\n";
    }
    else{
        cout << "YES" << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}