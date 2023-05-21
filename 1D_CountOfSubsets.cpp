#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int t[100][100];

int countofsubsets(int arr[], int n, int sum)
{
    if (n==0 && sum>0)
        return 0;
    if (sum==0)
        return 1;
    
    if (t[n][sum]!=-1)
        return t[n][sum];

    if (arr[n-1]<=sum)
        return t[n][sum] = countofsubsets(arr, n-1, sum-arr[n-1]) + countofsubsets(arr, n-1, sum);
    else
        return t[n][sum] = countofsubsets(arr, n-1, sum);

    return t[n][sum];
}

int main()
{
    memset(t, -1, sizeof(t));
    
    int arr[4]={2, 2, 2 ,2 };
    int diff=0;
    int range=8;
    int s1=(range+diff)/2;
    cout<<countofsubsets(arr, 4, s1);
    
}