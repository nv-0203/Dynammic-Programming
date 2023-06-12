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
    
    int n; cin>>n;
    int arr[n];
    int total=0;
    for (int i=0; i<n; i++)
    {
        cin>>arr[i];
        total+=arr[i];
    }

    vector<vector<bool>> dp(n+1, vector<bool> (total+1));

    for (int i=1; i<=total; i++) {dp[0][i]=false;}
    for (int i=0; i<=n; i++) {dp[i][0]=true;}

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=total; j++)
        {
            if (arr[i-1]<=j)
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j]; 
        }
    }

    vector<int> output;
    for (int i=1; i<=total; i++)
    {
        if (dp[n][i]==true)
            output.push_back(i);
    }
    cout<<output.size()<<endl;
    
    for (int i=0; i<output.size(); i++)
    {
        cout<<output[i]<<" ";
    }
}