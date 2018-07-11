//============================================================================
// Problem  : 962D - Merge Equals
// Category : Map
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll x,n;
    map<ll,ll> mp;
    while(cin >> n)
    {
        mp.clear();
        for(ll i = 0; i < n; i++)
        {
            cin >> x;
            while(mp.find(x) != mp.end())
            {
                mp.erase(x);
                x += x;
            }
            mp[x] = i;
        }
        vii v;
        for(auto it : mp)
            v.push_back({it.second, it.first});
        sort(v.begin(), v.end());
        cout << v.size() << '\n';
        for(ii x : v)
            cout << " " << x.second;
        cout << '\n';
    }
    return 0;
}