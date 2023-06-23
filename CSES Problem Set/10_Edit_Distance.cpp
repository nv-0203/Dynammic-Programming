#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <math.h>
#include <vector>
#include <iomanip>
#include <queue>
#include <stack>
using namespace std;
typedef long long int ll;

int mod = 1e9 + 7;
int t[5001][5001];

int solve (int i, int j, string &a, string &b)
{
    if (a.length()==i || b.length()==j)
        return max((int)a.length()-i, (int)b.length()-j);
    
    if (t[i][j] != -1)
        return t[i][j];

    int ans;
    if (a[i]==b[j])
        ans = solve(i+1, j+1, a, b);
    else {
        int op1 = 1 + solve(i, j+1, a, b); //insert
        int op2 = 1 + solve(i+1, j, a, b); //delete
        int op3 = 1 + solve(i+1, j+1, a, b); //replace
        ans = min(op1, min(op2, op3));
    }
    return t[i][j] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string a, b;
    cin>>a>>b;
    memset(t, -1, sizeof(t));
    cout<<solve(0, 0, a, b);


}