#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int t[100][100];

bool subsetsum(int arr[], int n, int sum)
{
    if (n==0 && sum>0)
        return 0;
    else if (sum==0)
        return 1;
    
    if (t[n][sum]!=-1)
        return t[n][sum];

    if (arr[n-1]<=sum)
        return t[n][sum]=subsetsum(arr, n-1, sum-arr[n-1]) || subsetsum(arr, n-1, sum);
    else
        return t[n][sum]=subsetsum(arr, n-1, sum);

    if (t[n][sum]==0)
        return false;
    else
        return true;
}

bool subset(int arr[], int n, int sum)
{
    bool t[n+1][sum+1];
    for (int i=0; i<=n; i++){
        t[i][0]=1;
    }
    for (int j=1; j<=sum; j++){
        t[0][j]=0;
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=sum; j++)
        {
            if (arr[i-1]<=j)
                t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
            else
                t[i][j]=t[i-1][j];
        }
    }
    return t[n][sum];
}

int main()
{
    int arr[5]={2, 5, 7, 8, 10};
    memset(t, -1, sizeof(t));
    cout<<subsetsum(arr, 5, 12);
}