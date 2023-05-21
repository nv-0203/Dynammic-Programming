#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int dp[101][51];

int solve(int n, int e)
{
    if (e==1)
        return n+1;
    if (n==0 || n==1)
        return n+1;

    int mini = n+1;
    for (int k=1; k<=n; k++)
    {
        int Break, NotBreak;
        if (dp[e-1][k-1] != -1)
            Break = dp[e-1][k-1];
        else
        {
            Break = solve(e-1, k-1);
            dp[e-1][k-1] = Break;
        }

        if (dp[e][n-k] != -1)
            NotBreak = dp[e][n-k];
        else
        {
            NotBreak = solve(e, n-k);
            dp[e][n-k] = NotBreak;
        }
        int temp = 1 + max(Break , NotBreak);
        mini = min (temp, mini);
    }
    return dp[n][e] = mini;
}

int main()
{
    int n, k;
    cin>>n>>k;
    memset(dp, -1, sizeof(dp));
    cout<<solve(n, k);
}