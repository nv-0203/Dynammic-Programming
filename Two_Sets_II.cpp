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

int dp[501][62626];

int countofsubsets(int arr[], int n, int sum)
{
    if (sum==0)
        return 1;
    if (n==0 && sum>0)
        return 0;

    if (dp[n][sum]!=-1)
        return dp[n][sum];

    if (arr[n-1]<=sum)
        return dp[n][sum] = (countofsubsets(arr, n-1, sum-arr[n-1]) + countofsubsets(arr, n-1, sum)) % mod;
    else
        return dp[n][sum] = countofsubsets(arr, n-1, sum);

    return dp[n][sum]%mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    int arr[n];
    for (int i=1; i<=n; i++)
    {
        arr[i-1]=i;
    }
    int sum = n*(n+1)/2;

    if (sum%2 != 0)
    {
        cout<<0;
        return 0;
    }
    
    memset(dp, -1, sizeof(dp));

    cout<<countofsubsets(arr, n-1, sum/2);



}