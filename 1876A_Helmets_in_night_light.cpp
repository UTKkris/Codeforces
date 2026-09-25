#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    int p;
    cin >> n;
    cin >> p;
    vector<int>a(n);
    vector<int>b(n);
    for(int i =0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i =0;i<n;i++)
    {
        cin >> b[i];
    }
    vector<pair<int,int>>person;
    for(int i=0;i<n;i++)
    {
        person.push_back({b[i],a[i]});
    }
    sort(person.begin(), person.end(), [](const pair<int,int>& x,
                                     const pair<int,int>& y) {
    if (x.first != y.first)
        return x.first < y.first;

    return x.second > y.second;
});
    long long minCost = p;
int personHeard = 1;

for(int i = 0; i < n; i++)
{
    if(personHeard >= n)
        break;

    int person_to_inform =
        min(n - personHeard, person[i].second);

    if(person[i].first <= p)
    {
        minCost += 1LL * person[i].first * person_to_inform;
        personHeard += person_to_inform;
    }
    else
    {
        minCost += 1LL * p * (n - personHeard);
        break;
    }
}
    cout << minCost << "\n";
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