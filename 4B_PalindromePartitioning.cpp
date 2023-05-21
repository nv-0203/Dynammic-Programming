#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

static int t[100][100];

bool isPalindrome(string s, int i, int j)
{
    while(i<j)
    {
        if (s[i]==s[j])
        {
            i++;
            j--;
        }
        else
            return false;
    }
    return true;
}

int solve(string s, int i, int j)
{
    if (i>=j)
        return 0;

    if (isPalindrome(s, i , j))
        return 0;

    if (t[i][j]!=-1)
        return t[i][j];

    int ans=INT_MAX;
    for (int k=i; k<j; k++)
    {
        int left, right;
        if (t[i][k]!= -1)
            left=t[i][k];
        else
        {
            left=solve(s, i, k);
            t[i][k] = left;
        }
        if (t[k+1][j]!= -1)
            right=t[k+1][j];
        else
        {
            right=solve(s, k+1, j);
            t[k+1][j] = right;
        }
        int temp = 1 + left + right;
        ans=min(ans, temp);
    }
    return t[i][j] = ans;
}

int main()
{
    memset(t, -1, sizeof(t));
    string s;
    cin>>s;
    cout<<solve(s, 0, s.length()-1);
}