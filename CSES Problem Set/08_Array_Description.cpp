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

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    
    int n, m;
    cin>>n>>m;

    int arr[n];
    for (int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    vector<vector<int>> dp(n, vector<int> (m+1, 0));
    
    if (arr[0]==0)
    {
        fill(dp[0].begin(), dp[0].end(), 1);
    }

    else
        dp[0][arr[0]]=1;

    for (int i=1; i<n; i++)
    {
        if (arr[i]==0)
        {
            for (int j=0; j<=m; j++)
            {
                for (int k : {j-1, j, j+1})
                {
                    if (k>=1 && k<=m)
                        (dp[i][j] += dp[i-1][k]) %= mod;
                }
            }
        }
        else
        {
            for (int k:{arr[i]-1, arr[i], arr[i]+1})
            {
                if (k>=1 && k<=m)
                    (dp[i][arr[i]]+= dp[i-1][k]) %= mod;
            }
        }
    }
    int ans=0;
    for (int i=1; i<=m; i++)
    {
        (ans+= dp[n-1][i]) %= mod;
    }
    cout<<ans;
}