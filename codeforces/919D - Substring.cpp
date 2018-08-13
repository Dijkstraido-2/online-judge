//============================================================================
// Judge    : 919D - Substring
// Category : DFS
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi g;
int n;

vi color;
int hasCycle;

void cycle(int v)
{
    color[v] = 1;
    for(int u : g[v])
        if(!color[u])
            cycle(u);
        else if(color[u] == 1)
            hasCycle = 1;
    color[v] = 2;
}

vi sorted;

void toposort(int v)
{
    color[v] = 1;
    for(int u : g[v])
        if(!color[u])
            toposort(u);
    sorted.push_back(v);
}

string s;
int f[300005][26];

void dfs(int v)
{
    color[v] = 1;
    for(int u : g[v])
    {
        if(!color[u])
            dfs(u);
        for(int i = 0; i < 26; i++)
            f[v][i] = max(f[v][i], f[u][i]);
    }
    f[v][s[v]-'a']++;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int m,x,y,ans;
    while(cin >> n >> m)
    {
        cin >> s;
        g = vvi(n);
        for(int i = 0; i < m; i++)
        {
            cin >> x >> y; x--; y--;
            g[x].push_back(y);
        }
        color = vi(n, 0); hasCycle = 0;
        for(int i = 0; i < n; i++)
            if(!color[i])
                cycle(i);
        if(hasCycle)
            cout << -1 << '\n';
        else
        {
            color = vi(n, 0); sorted.clear();
            for(int i = 0; i < n; i++)
                if(!color[i])
                    toposort(i);
            reverse(sorted.begin(), sorted.end());
            memset(f, 0, sizeof f);
            color = vi(n, 0); ans = 0;
            for(int v : sorted)
                if(!color[v])
                {
                    dfs(v);
                    for(int i = 0; i < 26; i++)
                        ans = max(ans, f[v][i]);
                }
            cout << ans << '\n';
        }
    }
    return 0;
} 