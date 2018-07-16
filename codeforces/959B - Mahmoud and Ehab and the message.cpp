//============================================================================
// Problem  : 959B - Mahmoud and Ehab and the message
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<string> vs;
typedef vector<int> vi;

vs v;
vi id;
map<string,ll> mp;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,k,m,cant;
    string s;
    while(cin >> n >> k >> m)
    {
        v = vs(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        mp.clear(); 
        for(int i = 0; i < n; i++)
            cin >> mp[v[i]];

        for(int i = 0; i < k; i++)
        {
            cin >> cant;
            id = vi(cant);
            cin >> id[0]; id[0]--;
            ll mini = mp[v[id[0]]];
            for(int j = 1; j < cant; j++)
            {
                cin >> id[j]; id[j]--;
                mini = min(mini, mp[v[id[j]]]);
            }
            for(int j = 0; j < cant; j++)
                mp[v[id[j]]] = mini;
        }
        ll ans = 0;
        for(int i = 0; i < m; i++)
        {
            cin >> s;
            ans += mp[s];
        }
        cout << ans << '\n';
    }
    return 0;
}