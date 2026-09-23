#include <iostream>
#include <string>

using namespace std;

void solve()
{
    string s;
    cin >> s;

    int n = s.size();

    int zeros = 0;
    int ones = 0;

    for (char c : s)
    {
        if (c == '0')       // digit zero
        {
            zeros++;
        }
        else
        {
            ones++;
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            if (ones > 0)
                ones--;
            else
            {
                ans = n - i;
                break;
            }
        }
        else
        {
            if (zeros > 0)
                zeros--;
            else
            {
                ans = n - i;
                break;
            }
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}