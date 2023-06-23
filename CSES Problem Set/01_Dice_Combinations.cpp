#include <iostream>
#include <map>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long int ll;

ll mod = 1e9 + 7;

ll com(ll n)
{
    ll t[n+1];
    memset(t, 0, sizeof(t));
    t[0]=1;
    for (ll i=1; i<=n; i++)
    {
        for (ll x=1; x<=6; x++)
        {
            if (x>i)
                break;
            t[i]= (t[i] + t[i-x]) % mod;
        }
    }
    return t[n];
}

int main()
{
    
    ll target;
    cin >> target;
    cout<<com(target);
}
