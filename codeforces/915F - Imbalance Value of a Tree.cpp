//============================================================================
// Problem  : 915F - Imbalance Value of a Tree
// Category : Union Find
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

struct DSU {
    vi p,s;

    DSU(int n) { 
        s = vi(n,1); p = vi(n); 
        iota(p.begin(), p.end(), 0); 
    }    
    
    int find(int i) { return (p[i] == i)? i : (p[i] = find(p[i])); }

    bool sameSet(int i, int j) { return find(i) == find(j); }
    
    void unite(int i, int j) { 
        int pi = find(i), pj = find(j); 
        if(pi == pj) return; 
        s[pj] += s[pi];
        p[pi] = pj;  
    }

    int sizeSet(int i) { return s[find(i)]; }
};

int n;
vi a,disc;
vvi g;

ll solve() 
{
    DSU ds = DSU(n);
    vii t;
    for(int i = 0; i < n; i++)
        t.push_back({a[i],i});
    sort(t.begin(), t.end());
    disc = vi(n,0);
    ll ans = 0;
    for(auto p : t)
    {
        int v = p.second;
        disc[v] = 1;
        for(int u : g[v])
            if(disc[u])
            {
                ll sz = ds.sizeSet(u);
                ans -= a[v]*sz*(sz-1)/2;
                ds.unite(v,u); 
            }
        ll sz = ds.sizeSet(v);
        ans += a[v]*sz*(sz-1)/2;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int x,y;
    while(cin >> n)
    {
        a = vi(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        g = vvi(n);
        for(int i = 0; i < n-1; i++)
        {
            cin >> x >> y; x--; y--;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        ll mx = solve();
        for(auto &x : a)
            x *= -1;
        ll mn = solve();
        cout << mx + mn << '\n';
    }
    return 0;
}