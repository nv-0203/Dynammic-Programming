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


int dp[1000001];

int main()
{
    ll n, sum;
    cin>>n>>sum;
    ll arr[n];
    for (ll i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    
    //dp[w] -> no of ordered ways to get sum w
    //dp[w] = dp[w] + dp[w - coins[i]]
    
    dp[0] = 1;
    for (int i=0; i<n; i++)
    {
        for (int x=0; x<=sum; x++)
        {
            if (x-arr[i] >= 0)
                dp[x] += dp[x-arr[i]];
            dp[x]%=mod;
        }
    }

    cout<<dp[sum]<<endl;
}