#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <math.h>
#include <vector>
#include <iomanip>
#include <queue>
#include <stack>
using namespace std;
typedef long long int ll;

int mod = 1e9 + 7;

int getBestCandidate(map<int, int> &mp, int v)
{
    auto it = mp.lower_bound(v);
    if (it==mp.begin())
    {
        return 0;
    }
    it--;
    return it->second;
}

void insert(map<int, int> &mp, int v, int adv)
{
    if (mp[v] >= adv)
        return;
    mp[v] = adv;
    auto it = mp.find(v);
    it++;
    while (it != mp.end() && adv >= it->second)
    {
        auto temp = it;
        it++;
        mp.erase(temp);
    }
}

int solve(vector<ll> &arr, int n)
{
    vector<int> dp(n);
    map<int, int> mp;
    dp[0]=1;
    mp[arr[0]]=1;
    for (int i=1; i<n; i++)
    {
        dp[i] = 1 + getBestCandidate(mp, arr[i]);
        insert(mp, arr[i], dp[i]);
    }

    return *max_element(dp.begin(), dp.end());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin>>n;
    vector<ll> arr(n);
    for (int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    cout<<solve(arr, n);
    
}