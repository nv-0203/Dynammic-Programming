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

bool sortcol (vector<ll> &v1, vector<ll> &v2) //function to sort vector on basis of second column
{
    return v1[1] < v2[1];
}

ll find_j(vector<ll> &v1, int x)
{
    auto ans = lower_bound(v1.begin(), v1.end(), x);
    
    if (ans == v1.begin())
        return 0;
    else
    {
        ans--;
        return 1 + distance(v1.begin(), ans);
    }
}

ll solveiterative(vector<vector<ll>> &v, int n)
{
    ll dp[n+1];
    dp[0]=0;

    vector<ll> endPts;
    for (int i=0; i<n; i++)
    {
        endPts.push_back(v[1][i]);
    }

    for (int i=0; i<n; i++)
    {
        ll op1 = dp[i];
        ll op2 = v[i][2];

        ll j = find_j(endPts, v[i][0]);
        op2 += dp[j];

        dp[i+1] = max(op1, op2);

        //cout<<dp[i]<<endl;
    }

    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    vector<vector<ll>> v(n, vector<ll> (3));
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<3; j++)
        {
            cin>>v[i][j];
        }
    }

    sort(v.begin(), v.end(), sortcol);
    
    cout<<solveiterative(v, n);
    
}