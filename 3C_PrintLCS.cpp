#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long int ll;

void printLCS(string x, string y, int n, int m)
{
    string s;
    int t[n+1][m+1];
    for (int i=0; i<=n; i++) {t[i][0]=0;}
    for (int j=0; j<=m; j++) {t[0][j]=0;}

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (x[i-1]==y[j-1])
                t[i][j]=1+t[i-1][j-1];
            else
                t[i][j]=max(t[i][j-1], t[i-1][j-1]);
        }
    }
    int i=n, j=m;
    while (i>0 & j>0)
    {
        if (x[i-1]==y[j-1])
        {
            s.push_back(x[i-1]);
            i--; j--;
        }
        else
        {
            if (t[i-1][j] > t[i][j-1])
                i--;
            else
                j--;
        }
    }
    reverse(s.begin(), s.end());
    cout<<s;
}

int main()
{
    string x, y;
    cin>>x>>y;
    int n=x.length();
    int m=y.length();
    printLCS(x, y, n, m);
}