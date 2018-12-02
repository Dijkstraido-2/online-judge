//============================================================================
// Problem  : 1082G - Petya and Graph
// Category : Max Flow
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<int SZ> struct dinic {
    struct edge { int u; ll flow, cap; int rev; };
    vector<edge> g[SZ]; 
    int dis[SZ],st[SZ];
     
    void add(int v, int u, ll f) {
        g[v].push_back({u,0,f,(int)g[u].size()});
        g[u].push_back({v,0,0,(int)g[v].size()}); 
    } 
     
    void clear() { for(int i = 0; i < SZ; i++) g[i].clear(); }

    bool bfs(int s, int t) {
        memset(st, 0, sizeof st);
        memset(dis, -1, sizeof dis); dis[s] = 0;      
        queue<int> q; q.push(s);
        while(!q.empty()) {
            int v = q.front(); q.pop();
            for(auto e : g[v]) 
                if(dis[e.u] < 0 && e.flow < e.cap) {
                    dis[e.u] = dis[v]+1;
                    q.push(e.u);
                }
        }
        return dis[t] >= 0;
    }
      
    ll dfs(int s, int t, ll flow) {
        if(s == t) return flow;
        for(auto &i = st[s]; i < (int)g[s].size(); i++) {
            edge &e = g[s][i]; ll tmp;
            if(dis[e.u] == dis[s]+1 && e.flow < e.cap && (tmp = dfs(e.u,t,min(flow,e.cap-e.flow))) > 0) {
                e.flow += tmp;
                g[e.u][e.rev].flow -= tmp;
                return tmp;
            }
        }
        return 0;
    }
     
    ll maxflow(int s, int t) {
        if(s == t) return -1;
        ll ans = 0;  
        while(bfs(s,t)) while(ll f = dfs(s,t,INT_MAX)) ans += f;
        return ans;
    } 
};

dinic<2005> g;
int n,m;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> m) {
        g.clear();
        for(int x = 1; x <= n; x++) {
            int w; cin >> w;
            g.add(m+x,2004,w);
        }
        ll sum = 0;
        for(int i = 1; i <= m; i++) {
            ll x,y,w; cin >> x >> y >> w; sum += w;
            g.add(0,i,w);
            g.add(i,m+x,INT_MAX);
            g.add(i,m+y,INT_MAX);
        }
        cout << sum-g.maxflow(0,2004) << '\n';
    }
    return 0;
}