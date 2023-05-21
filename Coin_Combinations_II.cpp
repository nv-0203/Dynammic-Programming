#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll mod = 1e9 + 7;

int dp[101][1000001];

int main()
{
    ll n, sum;
    cin>>n>>sum;
    ll arr[n];
    for (ll i=0; i<n; i++)
    {
        cin>>arr[i];
    }
     
    for (ll i=0; i<=n; i++) { dp[i][0] = 1; }
    for (ll j=1; j<=sum; j++) { dp[0][j] = 0; }

    for (ll i=1; i<=n; i++)
    {
        for (ll j=1; j<=sum; j++)
        {
            if (arr[i-1] <= j)
                dp[i][j] = (dp[i-1][j] + dp[i][j-arr[i-1]]) % mod;
            else
                dp[i][j] = (dp[i-1][j]) % mod; 
        }
    }
    cout << dp[n][sum];
}