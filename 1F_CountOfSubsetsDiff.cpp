#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void subsetdiff(int arr[], int n, int range, int diff)
{
    int t[n + 1][range + 1];
    for (int i = 0; i <= n; i++)
    {
        t[i][0] = 1;
    }
    for (int j = 1; j <= range; j++)
    {
        t[0][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= range; j++)
        {
            if (arr[i - 1] <= j)
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
            else
                t[i][j] = t[i - 1][j];
        }
    }
    int s2 = (range + diff) / 2;
    int s1 = s2 - diff;

    int ans = min(t[n][s1], t[n][s2]);
    cout << ans;
}
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
    int n;
    cin >> n;
    int arr[n];
    int range = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        range += arr[i];
    }
    int diff;
    cin >> diff;
    int sum=(range+diff)/2;
    //subsetdiff(arr, n, range, diff);
    cout<<countofsubsets(arr, n, sum);
    return 0;
}
