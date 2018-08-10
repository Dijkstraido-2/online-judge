//============================================================================
// Judge    : 918B - Radio Station
// Category : Map
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,k;
    string name,ip;
    map<string,string> mp;
    while(cin >> n >> m)
    {
        mp.clear();
        for(int i = 0; i < n; i++)
        {
            cin >> name >> ip;
            mp[ip] = name;
        }
        for(int i = 0; i < m; i++)
        {
            cin >> name >> ip;
            k = ip.size();
            cout << name << " " << ip << " #" << mp[ip.substr(0,k-1)] << '\n';
        }
    }
    return 0;
} 