#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <iomanip>
using namespace std;
typedef long long int ll;

int mod = 1e9 + 7;

int main()
{
    int n; cin>>n;
    vector<vector<char>> grid(n, vector<char> (n));
    
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cin>>grid[i][j];
        }
    }

    int dp[n][n];
    for (int i=0; i<n; i++)
    {
        if (grid[0][i]=='.')
            dp[0][i]=1;
        else if (grid[0][i] == '*')
        {
            while (i<n)
            {
                dp[0][i]=0;
                i++;
            }
        }
    }
    for (int i=0; i<n; i++)
    {
        if (grid[i][0]=='.')
            dp[i][0]=1;
        else if (grid[i][0] == '*')
        {
            while (i<n)
            {
                dp[i][0]=0;
                i++;
            }
        }
    }

    for (int i=1; i<n; i++)
    {
        for (int j=1; j<n; j++)
        {
            if (grid[i][j]=='*')
                dp[i][j]=0;
            else
                dp[i][j]= (dp[i-1][j] + dp[i][j-1])%mod;
        }
    }

    cout<<dp[n-1][n-1];


}