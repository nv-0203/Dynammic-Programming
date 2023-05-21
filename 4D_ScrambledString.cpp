#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long int ll;

unordered_map<string, bool> mp;

bool solve(string a, string b)
{
    if (a.length() != b.length())
        return false;
    if (a.empty() && b.empty())
        return true;
    if (a.compare(b) == 0)
        return true;
    if (a.length() <= 1)
        return false;
    
    string temp=a+" "+b;
    if (mp.find(temp) != mp.end())
        return mp[temp];

    int n=a.length();
    bool flag = false;
    for (int i=1; i<n; i++)
    {
        if (solve(a.substr(0,i), b.substr(0, i)) && solve(a.substr(i, n-i), b.substr(i, n-i)))
        {
            flag = true;
            break;
        }
        if (solve(a.substr(0,i), b.substr(n-i, i)) && solve(a.substr(i, n-i), b.substr(0, n-i)))
        {
            flag = true;
            break;
        }
    }
    return mp[temp] = flag;
}

int main()
{
    string a, b;
    cin>>a>>b;
    cout<<solve(a, b);

}