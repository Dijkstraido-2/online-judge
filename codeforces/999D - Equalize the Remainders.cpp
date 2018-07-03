//============================================================================
// Problem  : 999D - Equalize the Remainders
// Category : Greedy + Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,m,k,ans,f[200005];
vector<ll> v,add;
set<ll> st;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> m)
    {
        k = n/m; v = vector<ll>(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        memset(f, 0, sizeof f); st.clear(); 
        for(int i = 0; i < m; i++)
            st.insert(i);
        ans = 0; add = vector<ll>(n, 0);
        for(int i = 0; i < n; i++)
        {
            ll cur = v[i] % m;
            auto it = st.lower_bound(cur);
            ll nxt = (it == st.end()? *st.begin() : *it); 
            ans += (nxt >= cur? nxt-cur : m-cur+nxt);
            add[i] += (nxt >= cur? nxt-cur : m-cur+nxt);
            f[nxt]++;
            if(f[nxt] == k)
                st.erase(nxt);
        }
        cout << ans << '\n';
        for(int i = 0; i < n; i++)
            cout << v[i] + add[i] << " ";
        cout << '\n';
    }
    return 0;
}