#include<bits/stdc++.h>

using namespace std;

void solve(){
    int x;
    int k;
    cin >> x >> k;
    vector<int>ans;
    int count =0;
    if(x<k)
    {
        cout << 1 << "\n";
        cout << x << "\n";
        return;
    }
    else if(x == k)
    {
        cout << 2 << "\n";
        cout << x-1 << " " << 1 << "\n"; 
        return;
    }
    else if(x>k)
    {
        for(int i=x;i>0;i--)
        {
            if(i % k !=0)
            {
                ans.push_back(i);
                count++;
                if(i == x)
                {
                    break;
                }
                if((x-i)%k !=0)
                {
                    count++;
                    ans.push_back(x-i);
                    break;
                }
            }
        }
    }
    cout << count << "\n";
    for(int i =0;i<ans.size();i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
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