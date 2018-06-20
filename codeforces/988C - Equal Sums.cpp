//============================================================================
// Problem  : 988C - Equal Sums
// Category : Map
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;

map<ll,ii> mp;
vi v;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t,n,s,ok;
    while(cin >> t)
    {
        mp.clear(); ok = 0;
        for(int k = 0; k < t; k++)
        {
            cin >> n;
            v = vi(n); s = 0;
            for(int i = 0; i < n; i++)
            {
                cin >> v[i];
                s += v[i];
            }

            for(int i = 0; i < n && !ok; i++)
            {
                if(!ok && mp.find(s-v[i]) != mp.end() && mp[s-v[i]].first != k)
                {
                    cout << "YES" << '\n';
                    cout << mp[s-v[i]].first +1 << " " << mp[s-v[i]].second+1 << '\n';
                    cout << k+1 << " " << i+1 << '\n';
                    ok = 1;
                }
                mp[s-v[i]] = {k,i};
            }
        }
        if(!ok)
            cout << "NO" << '\n';
    }
    return 0;
}