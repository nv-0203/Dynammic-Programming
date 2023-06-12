#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <iomanip>
using namespace std;
typedef long long int ll;

//int dp[1001][100001];

// int solve(int price[], int pages[], int x, int n)
// {
//     if (n==0 || x==0)
//         return 0;
//     if (dp[n][x]!=-1)
//         return dp[n][x];

//     if (price[n-1]<=x)
//         return dp[n][x] = max(pages[n-1] + solve(price, pages, x-price[n-1], n-1), solve(price, pages, x, n-1));
//     else
//         return dp[n][x] = solve(price, pages, x, n-1);

//     return dp[n][x];
// }

int main()
{
    

    int n, x;
    cin>>n>>x;

    int price[n];
    for (int i=0; i<n; i++)
    {
        cin>>price[i];
    }

    int pages[n];
    for (int i=0; i<n; i++)
    {
        cin>>pages[i];
    }
    // memset(dp, -1, sizeof(dp));
    // cout<<solve(price, pages, x, n);

    //vector<vector<int>> dp(n+1, vector<int> (x+1));
    int dp[n+1][x+1];
    for (int i=0; i<=n; i++) {dp[i][0] = 0;}
    for (int i=0; i<=x; i++) {dp[0][i] = 0;}

    

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=x; j++)
        {
            if (price[i-1] <= j)
                dp[i][j] = max(pages[i-1] + dp[i-1][j-price[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    cout<<dp[n][x];
  
}