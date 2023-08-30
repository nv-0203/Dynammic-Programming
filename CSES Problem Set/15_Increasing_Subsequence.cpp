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

int solve(vector<ll> &arr, int n)
{
    vector<ll> dp;
    dp.push_back(0);

    for (int i=0; i<n; i++)
    {
        auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
        if (it == dp.end())
            dp.push_back(arr[i]);
        else
        {
            int idx = it - dp.begin();
            dp[idx] = min(dp[idx], arr[i]);
        }
    }

    return dp.size()-1;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin>>n;
    vector<ll> arr(n);
    for (int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
 
    cout<<solve(arr, n);
    
}