#include<iostream>
#include<string>

using namespace std;

void solve()
{
    int n ;
    string s;
    int q;
    cin >> n;
    cin >> s;
    cin>>q;
    int p=0;
    int m=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='+')
        {
            p++;
        }
        else{
            m++;
        }
    }
    for(int i =0;i<q;i++)
    {
        long long k=0;
        long long a;
        long long b;
        long long num=0;
        long long den=0;
        cin >>a>>b;
        if(a==b)
        {
            if(p==m)
            {
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
            continue;
        }
        num = -b*(p-m);
        den = a-b;
        k=num/den;
        if((num%den == 0) && (k<=p) && (k>=-m)){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}