//Longest Common Subsequence

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

static int t[100][100];

int LCS(string x, string y, int n, int m)
{
    if (n==0 || m==0)
        return 0;

    if (t[n][m]!=-1)
        return t[n][m];

    if (x[n-1]==y[m-1])
        return t[n][m] = 1 + LCS (x, y, n-1, m-1);
    
    else 
        return t[n][m] = max (LCS(x, y, n-1, m), LCS(x, y, n, m-1));

    return t[n][m];
}

int main()
{
    memset(t, -1, sizeof(t));
    string x, y;
    cin>>x>>y;
    int n=x.length();
    int m=y.length();
    cout<<LCS(x, y, n, m);
}