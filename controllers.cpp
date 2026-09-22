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
        int k=0;
        int a;
        int b;
        long long num=0;
        int den=0;
        cin >>a>>b;
        if(a==b)
        {
            if(p==m)
            {
                cout<<"YES";
            }
            else{
                cout<<"NO";
            }
            break;
        }
        num = -b*(p-m);
        den = a-b;
        k=num/den;
        if((num%den == 0) && (k<=p) && (k>=-m)){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}