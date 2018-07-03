//============================================================================
// Problem  : 999E - Reachability from the Capital
// Category : SCC + Topsort
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

vii in;
vvi g,r,dag;
int n,m,s;
vi color,st,scc;
int nSCC; 

void dfs(int v, int flag) 
{
    color[v] = 1;      
    for(int u : (flag? g[v] : r[v])) 
        if(!color[u]) 
            dfs(u, flag); 
    if(flag) 
        st.push_back(v); 
    else 
        scc[v] = nSCC; 
}

void getSCC()
{
    color = vi(n, 0); st.clear();
    for(int i = 0; i < n; i++)
        if(!color[i])
            dfs(i, 1);
    color = vi(n, 0); scc = vi(n); nSCC = 0;
    for(int i = n-1; i >= 0; i--)
        if(!color[st[i]])
        {
            dfs(st[i], 0);
            nSCC++;
        }
}

void getDAG()
{
    dag = vvi(nSCC);
    for(ii e : in)
        if(scc[e.first] != scc[e.second])
            dag[scc[e.first]].push_back(scc[e.second]);
}

vi sorted;
int flag;

void dfs(int v)
{
    color[v] = 1; 
    for(int u : dag[v]) 
        if(!color[u]) 
            dfs(u); 
    if(flag) sorted.push_back(v);
}

void topsort() 
{
    color = vi(nSCC, 0); sorted.clear(); flag = 1;
    for(int i = 0; i < nSCC; i++) 
        if(!color[i]) 
            dfs(i); 
    reverse(sorted.begin(),sorted.end()); 
}

int solve()
{
    int ans = 0;
    color = vi(nSCC, 0); flag = 0;
    for(int v : sorted)
        if(!color[v])
        {
            if(scc[s] != v)
                ans++;
            dfs(v);
        }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int x,y;
    while(cin >> n >> m >> s)
    {
        g = vvi(n); r = vvi(n); in = vii(m); s--; 
        for(int i = 0; i < m; i++)
        {
            cin >> x >> y; x--; y--;
            g[x].push_back(y); r[y].push_back(x); in[i] = {x,y};
        }
        getSCC();
        getDAG();
        topsort();
        cout << solve() << '\n';
    }
    return 0;
}