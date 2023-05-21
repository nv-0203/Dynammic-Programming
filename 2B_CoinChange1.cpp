#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

//max no of ways in which sum can be obtained from the given coins (unlimited supply)

static int t[1000][1000];

int coinchange(int coin[], int n, int sum)
{
    if (n==0 && sum>0)
        return 0;
    if (sum==0)
        return 1;
    

    if (t[n][sum]!=-1)
        return t[n][sum];

    if (coin[n-1]<=sum)
        return t[n][sum] = coinchange(coin, n-1, sum) + coinchange(coin, n, sum-coin[n-1]);
    else
        return t[n][sum] = coinchange (coin, n-1, sum);

    return t[n][sum];

}

int main()
{
    memset(t, -1, sizeof(t));
    int n, sum;
    cin>>n>>sum;
    int coin[n];
    for (int i=0; i<n; i++)
    {
        cin>>coin[i];
    }
    cout<<coinchange(coin, n, sum);

}