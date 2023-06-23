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

void solve()
{

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;

    ll arr[n];
    ll sum=0;
    for (int i=0; i<n; i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }

    vector<vector<ll>> dp(n, vector<ll> (n));

    for (int l=n-1; l>=0; l--)
    {
        for (int r=l; r<n; r++)
        {
            if (l==r)
                dp[l][r] = arr[l];
            else
                dp[l][r] = max (arr[l] - dp[l+1][r], arr[r] - dp[l][r-1]);
        }
    }

    cout<<(dp[0][n-1] + sum)/2;
}