#include<iostream>
#include<string>

using namespace std;

void solve(){

    int n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
    int bad_pairs = 0;
    //towerA checking for duplicates
    for(int i =0;i<n-1;i++)
    {
        if(s[i]==s[i+1]) bad_pairs++;
    }
    //towerB checking for duplicates
    for(int i =0;i<m-1;i++)
    {
        if(t[i]==t[i+1]) bad_pairs++;
    }
    
    if(s.back()==t.back())
    {
        bad_pairs++;
    }
    if(bad_pairs<=1)
    {
        cout<<"yes\n";
    }
    else{
        cout<<"no\n";
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