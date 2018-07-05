//============================================================================
// Problem  : 979C - Kuro and Walking Route
// Category : DFS
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi g;
ll n,p[2],sel;
vi sub,has;

int dfs(int v, int p = -1)
{
    sub[v] = 1;
    for(int u : g[v])
        if(u != p)
            sub[v] += dfs(u,v);
    return sub[v];
}

int bad(int v, int p = -1)
{
    has[v] = (v == sel);
    for(int u : g[v])
        if(u != p)
            has[v] = (has[v] || bad(u,v));
    return has[v];
}

ll solve()
{
    ll sz[2]; sz[0] = sz[1] = 1;
    for(int i = 0; i < 2; i++)
    {
        sub = vi(n,0); has = vi(n); sel = p[!i];
        dfs(p[i]); bad(p[i]);
        for(int u : g[p[i]])
            if(!has[u])
                sz[i] += sub[u];
    }
    return n*(n-1) - sz[0]*sz[1];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int x,y;
    while(cin >> n >> p[0] >> p[1])
    {
        g = vvi(n); p[0]--; p[1]--;
        for(int i = 0; i < n-1; i++)
        {
            cin >> x >> y; x--; y--;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        cout << solve() << '\n';
    }
    return 0;
}