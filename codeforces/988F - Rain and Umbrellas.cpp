//============================================================================
// Problem  : 988F - Rain and Umbrellas
// Category : DP
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a,m,n;
ll event[2005],cost[2005],has[2005],id[2005],dp[2005][2005][2];
const ll INF = 200000000000LL;

ll solve(int pos, int umb, int rains) 
{
    if(rains && !umb) return INF;
    if(pos == a) return 0;
    if(dp[pos][umb][rains] != -1) return dp[pos][umb][rains];
    ll ans = INF;
    int nrains = event[pos]==1? 1 : event[pos]==2? 0 : rains;
    if(umb)
        ans = min(ans, cost[umb] + solve(pos+1, umb, nrains));
    if(has[pos])
        ans = min(ans, cost[id[pos]] + solve(pos+1, id[pos], nrains));
    if(!rains || event[pos] == 2)
        ans = min(ans, solve(pos+1, 0, nrains));
    return dp[pos][umb][rains] = ans;
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll l,r,x,ans;
    while(cin >> a >> m >> n)
    {
        memset(event, 0, sizeof event);
        for(int i = 0; i < m; i++)
        {
            cin >> l >> r;
            event[l] = 1; event[r] = 2;
        }
        memset(has, 0, sizeof has);
        memset(id, -1, sizeof id);
        for(int i = 1; i <= n; i++)
        {
            cin >> x >> cost[i];
            has[x] = 1; 
            if(id[x] == -1 || cost[i] < cost[id[x]])
                id[x] = i;
        }
        memset(dp, -1, sizeof dp);
        ans = solve(0,0,0);
        cout << (ans == INF? -1 : ans) << '\n';
    }
    return 0;
}