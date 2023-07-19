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
#include <stdlib.h>
#include <assert.h>
#include <iomanip>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define eps 1e-9
#define mod 1000000007

const int mxN = 1e6 + 6;
ll dp[mxN][3];

void solve()
{

    dp[1][1] = 1;
    dp[1][2] = 1;

    for (int i = 2; i < mxN; i++)
    {
        dp[i][1] = (dp[i-1][1]*4 + dp[i - 1][2]) % mod;
        dp[i][2] = (dp[i-1][1] + dp[i-1][2]*2) % mod;
    }

    // dp[i][x] -> x == 1(full)    x == 2 (splitted)
    // dp[i+1][1] = dp[i][1]*2 + dp[i][1]
    // dp[i+1][2] = dp[i][2]*4 + dp[i][2]
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;
    cin >> test;
    solve();
    while (test--)
    {
        ll n;
        cin >> n;
        ll ans = (dp[n][1] + dp[n][2]) % mod;
        cout << ans << endl;
    }
    return 0;
}