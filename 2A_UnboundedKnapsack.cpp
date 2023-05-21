#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

static int t[100][100];

int knapsack(int val[], int wt[], int n, int W)
{
    if (n==0 || W==0)
        return 0;
    if (t[n][W]!=-1)
        return t[n][W];
    if (wt[n-1]<=W)
        return t[n][W] = max (val[n-1] + knapsack(val, wt, n, W-wt[n-1]), knapsack(val, wt, n-1, W));
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