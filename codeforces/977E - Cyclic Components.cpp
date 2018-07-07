//============================================================================
// Problem  : 977E - Cyclic Components
// Category : DFS
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi g;
int n,k;
vi deg,pset,color;

void dfs(int v)
{
    color[v] = 1;
    pset[v] = k;
    for(int u : g[v])
        if(!color[u])
            dfs(u);
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int m,x,y;
    while(cin >> n >> m)
    {
        g = vvi(n); deg = vi(n,0);
        for(int i = 0; i < m; i++)
        {
            cin >> x >> y; x--; y--;
            g[x].push_back(y);
            g[y].push_back(x);
            deg[x]++; deg[y]++;
        }
        color = vi(n, 0); pset = vi(n); k = 0;
        for(int i = 0; i < n; i++)
            if(!color[i])
                dfs(i), k++;
        vi isCycle = vi(k, 1);
        for(int i = 0; i < n; i++)
            isCycle[pset[i]] = isCycle[pset[i]] && (deg[i] == 2);

        int ans = 0;
        for(int i = 0; i < k; i++)
            if(isCycle[i])
                ans++;
        cout << ans << '\n';
    }
    return 0;
}