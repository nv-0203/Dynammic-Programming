#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int t[201][201][2];

int solve(string s, int i, int j, bool isTrue)
{
    if (i>j)
        return false;
    if (i==j)
    {
        if (isTrue == true)
            return s[i]=='T';
        else
            return s[i]=='F';
    }
    if (t[i][j][isTrue] != -1)
        return t[i][j][isTrue];

    int ans=0;

    for (int k=i+1; k<j; k=k+2)
    {
        int lT = solve(s, i, k-1, true);
        int lF = solve(s, i, k-1, false);
        int rT = solve(s, k+1, j, true);
        int rF = solve(s, k+1, j, false);

        if (s[k] == '^')
        {
            if (isTrue == true)
                ans += lT*rF + lF*rT;
            else
                ans += lT*rT + lF*rF;
        }
        if (s[k] == '&')
        {
            if (isTrue == true)
                ans += lT*rT;
            else
                ans += lT*rF + lF*rF + lF*rT;
        }
        if (s[k] == '|')
        {
            if (isTrue == true)
                ans += lT*rF + lF*rT + lT*rT;
            else
                ans += lF*rF;
        }

    }
    return t[i][j][isTrue] = ans;
}

int main()
{
    int n; cin>>n;
    string s;
    cin>>s;
    memset(t, -1, sizeof(t));
    cout<<solve(s, 0, n-1, true);
}

// faster solution: 
// int lT, rT, lF, rF;
// if (t[i][k-1][1] != -1)
//     lT = t[i][k-1][1];
// else
// {
//     lT = solve(s, i, k-1, true);
//     t[i][k-1][1] = lT;
// }
// if (t[i][k-1][0] != -1)
//     lF = t[i][k-1][0];
// else
// {
//     lF = solve(s, i, k-1, false);
//     t[i][k-1][0] = lF;
// }
// if (t[k+1][j][1] != -1)
//     rT = t[k+1][j][1];
// else
// {
//     rT = solve(s, k+1, j, true);
//     t[k+1][j][1] = rT;
// }
// if (t[k+1][j][0] != -1)
//     rF = t[k+1][j][0];
// else
// {
//     rF = solve(s, k+1, j, false);
//     t[k+1][j][0] = rF;
// }

