#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool subsetsum(int arr[], int n, int sum)
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

bool equalsum(int arr[], int n)
{
    int sum=0;
    for (int i=0; i<n; i++)
    {
        sum+=arr[i];
    }
    if (sum%2!=0)
        return false;
    return subsetsum(arr, n, sum/2);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<equalsum(arr, n);
}