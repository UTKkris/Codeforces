#include<bits/stdc++.h>
#include<iostream>

using namespace std;

void solve()
{
    vector<vector<char>>arr(10, vector<char>(10,0));
    for(int i =0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            cin >> arr[i][j];
        }
    }
    int row = 0;
    int col = 0;
    int cost = 0;
    for(int i =0;i<100;i++)
    {
        row = i/10;
        col = i%10;
        if(arr[row][col] == 'X' && (row == 0 || row == 9 || col == 0 || col == 9))
        cost += 1;
    else if(arr[row][col] == 'X' && (row == 1 || row == 8 || col == 1 || col == 8))
        cost += 2;
    else if(arr[row][col] == 'X' && (row == 2 || row == 7 || col == 2 || col == 7))
        cost += 3;
    else if(arr[row][col] == 'X' && (row == 3 || row == 6 || col == 3 || col == 6))
        cost += 4;
    else if(arr[row][col] == 'X' && (row == 4 || row == 5 || col == 4 || col == 5))
        cost += 5;
        }
    cout << cost << "\n";
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