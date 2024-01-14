#include <iostream>
using namespace std;
typedef long long int ll;

int KnapSack(int val[], int wt[], int n, int W)
{
    // array to store final result
    // dp[i] stores the profit with KnapSack capacity "i"
    int dp[W + 1];
 
    // initially profit with 0 to W KnapSack capacity is 0
    memset(dp, 0, sizeof(dp));
 
    // iterate through all items
    for (int i = 0; i < n; i++)
        // traverse dp array from right to left
        for (int j = W; j >= wt[i]; j--)
            dp[j] = max(dp[j], val[i] + dp[j - wt[i]]);
    /*above line finds out maximum of  dp[j](excluding ith
      element value) and val[i] + dp[j-wt[i]] (including ith
      element value and the
      profit with "KnapSack capacity - ith element weight")
    */
    return dp[W];
}

static int t[100][100];

int knapsack(int val[], int wt[], int n, int W)
{
    if (n==0 || W==0)
        return 0;
    if (t[n][W]!=-1)
        return t[n][W];
    if (wt[n-1]<=W)
        return t[n][W] = max (val[n-1] + knapsack(val, wt, n-1, W-wt[n-1]), knapsack(val, wt, n-1, W));
    else
        return t[n][W] = knapsack(val, wt, n-1, W);

}

int main()
{
    memset(t, -1, sizeof(t));
    int n, W;
    cin>>n>>W;
    int val[n];
    int wt[n];
    for (int i=0; i<n; i++)
    {
        cin>>wt[i];
    }
    for (int i=0; i<n; i++)
    {
        cin>>val[i];
    }
    
    cout<<knapsack(val, wt, n, W);
    return 0;
}