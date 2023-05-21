#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long int ll;

void supersequence(string x, string y, int n, int m)
{
    int t[n+1][m+1];
    for (int i=0; i<=n; i++) {t[i][0]=i;}
    for (int i=0; i<=m; i++) {t[0][i]=i;}
    
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (x[i-1]==y[j-1])
                t[i][j] = max (t[i-1][j], t[i][j-1]);
            else
                t[i][j] = 1 + min (t[i-1][j], t[i][j-1]);
        }
        
    }
    // for (int i=0; i<=n; i++)
    // {
    //     for (int j=0; j<=m; j++)
    //     {
    //         cout<<t[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    string s;
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
            if (t[i-1][j] >= t[i][j-1])
            {
                s.push_back(y[j-1]);
                j--;
            }
            else 
            {
                s.push_back(x[i-1]);
                i--;
            }
        }
    }
    while (i>0)
    {
        s.push_back(x[i-1]);
        i--;
    }
    while (j>0)
    {
        s.push_back(y[j-1]);
        j--;
    }
    reverse(s.begin(), s.end());
    cout<<s;

}

int main()
{
    string x, y;
    cin>>x>>y;
    int n=x.length(), m=y.length();
    supersequence(x, y, n, m);
}