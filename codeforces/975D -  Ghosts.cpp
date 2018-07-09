//============================================================================
// Problem  : 975D -  Ghosts
// Category : Geometry + Map
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    ll a,b,x,vx,vy,ans;
    map<ll,int> mp;
    map<pair<ll,ll>,int> st;
    while(cin >> n >> a >> b)
    {
        ans = 0; mp.clear(); st.clear();
        for(int i = 0; i < n; i++)
        {
            cin >> x >> vx >> vy;
            ans += mp[a*vx-vy]++;
            ans -= st[{vx,vy}]++;
        }
        cout << 2*ans << '\n';
    }
    return 0;
}