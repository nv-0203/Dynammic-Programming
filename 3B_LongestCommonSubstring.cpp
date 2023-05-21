#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int LCSubstring(string x, string y, int n, int m)
{
    int t[n+1][m+1];
    int maxi=0;
    for (int i=0; i<=n; i++){
        t[i][0]=0;
    }
    for (int j=0; j<=m; j++){
        t[0][j]=0;
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (x[i-1]==y[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else
                t[i][j] = 0;
            maxi=max(t[i][j], maxi);
        }
    }
    
    return maxi;
}

int main()
{
    string x, y;
    cin>>x>>y;
    int n=x.length(), m=y.length();
    cout<<LCSubstring(x, y, n, m);
}