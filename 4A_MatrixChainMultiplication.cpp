#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

static int t[101][101];

int solve(int arr[], int i, int j)
{
    if (i >= j)
        return 0;
    if (t[i][j] != -1)
        return t[i][j];

    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp = solve(arr, i, k) + solve(arr, k+1, j) + (arr[i-1] * arr[k] * arr[j]);
        ans = min(ans, temp);
    }

    return t[i][j] = ans;
}

int main()
{
    memset(t, -1, sizeof(t));
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << solve(arr, 1, n - 1);
}