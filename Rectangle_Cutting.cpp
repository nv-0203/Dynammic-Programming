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
int dp[501][501];

int solve(int a, int b)
{
    if (a==b)
        return 0;
    if (dp[a][b]!=-1)
        return dp[a][b];

    int mn=INT_MAX;

    for (int k=1; k<a; k++)
    {
        int left, right;
        if (dp[k][b]!=-1)
            left=dp[k][b];
        else
        {
            left=solve(k,b);
            dp[k][b]=left;
        }
        if (dp[a-k][b]!=-1)
            right=dp[a-k][b];
        else
        {
            right=solve(a-k,b);
            dp[a-k][b]=right;
        }
        mn = min (mn, 1 + left + right);
    }

    for (int l=1; l<b; l++)
    {
        int up, down;
        if (dp[a][l]!=-1)
            up=dp[a][l];
        else
        {
            up=solve(a,l);
            dp[a][l]=up;
        }
        if (dp[a][b-l]!=-1)
            down=dp[a][b-l];
        else
        {
            down=solve(a,b-l);
            dp[a][b-l]=down;
        }
        mn = min(mn, 1 + up + down);
    }

    return dp[a][b] = mn;
    
    
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b;
    cin>>a>>b;

    memset(dp, -1, sizeof(dp));
    cout<<solve(a, b);

}