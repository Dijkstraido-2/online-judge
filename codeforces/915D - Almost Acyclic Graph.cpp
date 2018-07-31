//============================================================================
// Problem  : 915D - Almost Acyclic Graph
// Category : Cycle finding + Brute force
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi g;
int n;
int forbid[505][505];
vi h,c;
vi color;
vi cycle;
bool hasCycle;

void dfs(int v, int d)
{
    color[v] = 1;
    h[v] = d;
    c.push_back(v);
    for(int u : g[v])
    {
        if(forbid[v][u])
            continue;
        if(!color[u])
            dfs(u, d + 1);
        else if(color[u] == 1)
        {
            hasCycle = true;
            if(cycle.empty())
            {
                for(int i = h[u]; i <= h[v]; i++)
                    cycle.push_back(c[i]);
                cycle.push_back(c[h[u]]);
            }
        }
    }
    color[v] = 2;
    c.pop_back();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int m,x,y;
    while(cin >> n >> m)
    {
        g = vvi(n);
        for(int i = 0; i < m; i++)
        {
            cin >> x >> y; x--; y--;
            g[x].push_back(y);
        }
        color = vi(n, 0); 
        cycle.clear();
        h = vi(n, 0);
        c = vi();
        memset(forbid, 0, sizeof forbid);
        for(int i = 0; i < n; i++)
            if(!color[i])
                dfs(i, 0);
        if(cycle.empty())
            cout << "YES" << '\n';
        else
        {
            bool found = false;
            for(int i = 0; i < (int)cycle.size() - 1; i++)
            {
                forbid[cycle[i]][cycle[i+1]] = 1;
                hasCycle = false;
                color = vi(n, 0); 
                for(int i = 0; i < n; i++)
                    if(!color[i])
                        dfs(i, 0);
                if(!hasCycle)
                {
                    cout << "YES" << '\n';
                    found = true;
                    break;
                }
                forbid[cycle[i]][cycle[i+1]] = 0;
            }
            if(!found)
                cout << "NO" << '\n';
        }
    }
    return 0;
}