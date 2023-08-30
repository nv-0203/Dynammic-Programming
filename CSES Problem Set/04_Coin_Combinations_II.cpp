#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <stdlib.h>
#include <assert.h>
#include <iomanip>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define eps 1e-9
#define mod 1000000007


int dp[101][1000001];

int main()
{
    ll n, sum;
    cin>>n>>sum;
    ll arr[n];
    for (ll i=0; i<n; i++)
    {
        cin>>arr[i];
    }
     
    for (ll i=0; i<=n; i++) { dp[i][0] = 1; }
    for (ll j=1; j<=sum; j++) { dp[0][j] = 0; }
    
    for (ll i=1; i<=n; i++)
    {
        for (ll j=1; j<=sum; j++)
        {
            if (arr[i-1] <= j)
                dp[i][j] = (dp[i-1][j] + dp[i][j-arr[i-1]]) % mod;
            else
                dp[i][j] = (dp[i-1][j]) % mod; 
        }
    }
    cout << dp[n][sum];
}