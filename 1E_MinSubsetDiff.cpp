#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void MinSubsetDiff(int arr[], int n, int sum)
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
    for (int i=sum/2; i>=0; i--)
    {
        if (t[n][i]==1)
        {
            cout<<sum-2*i;
            break;
        }
    }
    
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    int range=0;
    for (int i=0; i<n; i++)
    {
        cin>>arr[i];
        range+=arr[i];
    }
    MinSubsetDiff(arr, n, range);
    return 0;
}