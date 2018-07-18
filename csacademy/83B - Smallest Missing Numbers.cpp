//============================================================================
// Problem  : 83B - Smallest Missing Numbers
// Category : Set
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n,m;
    vi v;
    set<ll> extra;
    cin >> n >> m;
    v = vi(n);
    for(int i = 0; i < n; i++) 
    {
        cin >> v[i];
        if(v[i] > m)
            extra.insert(v[i]);
    }
    ll ans = m*(m+1)/2, nxt = m+1;
    for(int i = 0; i < n; i++)
        if(v[i] <= m) 
        {
            ans -= v[i];
            while(extra.find(nxt) != extra.end())
                nxt++;
            ans += nxt;
            extra.insert(nxt);
        }
    cout << ans << '\n';
    return 0;
}