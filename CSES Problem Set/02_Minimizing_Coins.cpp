#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

static int t[101][1000001];


ll minimizing(ll coins[], ll n, ll sum)
{
    for (ll i=0; i<=sum; i++) {t[0][i]=INT_MAX-1;}
    for (ll j=1; j<=n; j++) { t[j][0] = 0;}
    
    for (ll i=1; i<=n; i++)
    {
        for (ll j=1; j<=sum; j++)
        {
            if (coins[i-1]<=j)
                t[i][j] = min((1 + t[i][j-coins[i-1]]), t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
        }
    }
    if ( t[n][sum] == INT_MAX - 1 ) 
        return -1;
    return t[n][sum];
}

int main()
{
    
    ll n, x;
    cin>>n>>x;
    ll coins[n];
    for (int i=0; i<n; i++)
    {
        cin>>coins[i];
    }
    cout<<minimizing(coins, n, x);
    
}