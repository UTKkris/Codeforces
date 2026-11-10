/*#include<bits/stdc++.h>
#include<iostream>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<char>arr(n);
    string s;
    cin >> s;
    int stack=0;
    vector<int>noPrint;
    for(int i =0;i<n;i++)
    {
        if(s[i] == '2' && stack == 0)
        {
            continue;
        }
        if(s[i] == '1')
        {
            noPrint.push_back(i+1);
            stack++;
        }
        else if(s[i] == '2' && stack !=0)
        {
            noPrint.pop_back();
            
            noPrint.push_back(i+1);
        }
        else if(s[i] == '3')
        {
            continue;
        }
    }
    int m = noPrint.size();
    cout << stack << "\n";
    for(int i =0;i<m;i++)
    {
        cout << noPrint[i] << " ";
    }
    cout << "\n";
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
}*/
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    stack<int> memory;
    vector<bool> printed(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == '1')
        {
            // Document i is stored in printer memory
            memory.push(i);
        }
        else if (s[i - 1] == '2')
        {
            if (!memory.empty())
            {
                // Print the topmost document from memory
                printed[memory.top()] = true;
                memory.pop();
            }
            else
            {
                // Memory is empty, so document i is printed
                printed[i] = true;
            }
        }
        else if (s[i - 1] == '3')
        {
            // Quick print: document i is printed
            printed[i] = true;
        }
    }

    vector<int> noPrint;

    for (int i = 1; i <= n; i++)
    {
        if (!printed[i])
        {
            noPrint.push_back(i);
        }
    }

    cout << noPrint.size() << '\n';

    for (int x : noPrint)
    {
        cout << x << ' ';
    }

    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}