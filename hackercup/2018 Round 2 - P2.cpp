//============================================================================
// Problem  : HackerCup 2018 Round 2 - Problem 2
// Category : DFS + Segment Tree
//============================================================================
// Compile with: g++ -std=c++11 -Wl,-stack_size -Wl,0x10000000 code.cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int MAX = 1000005;

vvi g;
int n;
int l[MAX],r[MAX],id[MAX],cur,h[MAX];

void dfs(int v)
{
    cur++; 
    id[cur] = v;
    l[v] = cur;
    for(auto u : g[v])
    {
        h[u] = h[v] + 1;
        dfs(u);
    }
    r[v] = cur;
}

struct node {
    ll val;
    int pos;
    node merge(const node &rhs) { 
        if(rhs.val >= val)
            return {rhs.val, rhs.pos};
        else
            return {val, pos};
    }
};

node t[MAX*2]; 

void build() 
{
    for(int i = n-1; i > 0; i--)   
        t[i] = t[i << 1].merge(t[i << 1 | 1]); 
}

void update(int i, ll x) 
{
    int pos = i;
    for(t[i += n] = {x, pos}; i >>= 1; )
        t[i] = t[i << 1].merge(t[i << 1 | 1]); 
}

node query(int l, int r) 
{
    node ans = {0LL,l};
    for(l += n, r += n; l <= r; l = (l+1) >> 1, r = (r-1) >> 1) 
    {
        if(  l & 1 ) ans = ans.merge(t[l]);
        if(!(r & 1)) ans = t[r].merge(ans);
    }
    return ans;
}

struct group { int q; };
group que[MAX];

bool operator < (const group &a, const group &b)
{
    return h[a.q] > h[b.q];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T,ntest=1;
    int m,a,b,p;
    cin >> T;
    while(T--)
    {
        cin >> n >> m >> a >> b;
        g = vvi(n);
        for(int i = 1; i < n; i++)
        {
            cin >> p;
            g[p].push_back(i);
        }
        cur = 0; h[0] = 0;
        dfs(0);
        for(int i = 0; i < n; i++)
            t[n+i] = {id[i+1],i};
        build();
        ll ans = 0;
        for(int i = 0; i < m; i++)
            que[i].q = (a*i + b) % n;
        sort(que, que+m);
        for(int i = 0; i < m; i++)
        {
            node par = query(l[que[i].q]-1, r[que[i].q]-1);
            ans += par.val;
            update(par.pos, 0);
        }
        cout << "Case #" << ntest++ << ": " << ans << '\n';
    }
    return 0; 
}