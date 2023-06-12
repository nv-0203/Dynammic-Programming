#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <iomanip>
using namespace std;
typedef long long int ll;
 
int dp[1000001];
 
int solve(int n)
{
    if (n<=9)
        return 1;
    if (n==0)
        return 0;
 
    if (dp[n] != -1)
        return dp[n];
    
    int mini=INT_MAX;
    int temp=n;
    while (temp != 0)
    {
        int x = temp%10;
        mini = min(mini, 1 + solve(n-x));
        temp/=10;
    }
 
    return dp[n] = mini;
    
    
 
}
 
int main()
{
    int n; cin>>n;
    string str=to_string(n);
    memset(dp, -1, sizeof(dp));
    cout<<solve(n);
}

// int main()
// {
//     int n; cin>>n;
    

//     vector<int> dp (n+1, 1e9);
//     dp[0] = 0;

//     for (int i=1; i<=n; i++)
//     {
//         for (char c : to_string(i))
//         {
//             int temp = 1 + dp[i-(c-'0')];
//             dp[i]=min(dp[i], temp);
//         }
//     }
//     cout<<dp[n];
// }