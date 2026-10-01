#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void solve(){
     int n;
     cin >> n;
     vector<int>arr(n);
     vector<int>divisors;
     int points =0;
     for(int i=0;i<n;i++)
     {
        cin >> arr[i];
     }
     for(int i=1;i<=n;i++)
     {
        if(i==n)
        {
            points++;
            break;
        }
        int g=0;
        if(n%i == 0)
        {
            for(int j=0;j<(n-i);j++)
            {
                g = gcd(g,arr[j]-arr[j+i]);
            }
            if(g!=1)
            {
                points++;    
            }
        }
        
     }
     cout << points << "\n";
}

int main(){
    ios::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >>t;
    while(t>0)
    {
        solve();
        t--;
    }
    return 0;
}