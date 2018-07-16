//============================================================================
// Problem  : 1006E - Military Problem
// Category : DFS
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi g;
int n;
vi sub,order,idx;

int dfs(int v) 
{
    sub[v] = 1;
    order.push_back(v);
    for(int u : g[v])
        sub[v] += dfs(u);
    return sub[v];
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int q,p,k;
    while(cin >> n >> q) 
    {
        g = vvi(n);
        for(int i = 1; i < n; i++) 
        {
            cin >> p; p--;
            g[p].push_back(i);
        }
        sub = vi(n,0); order.clear();
        dfs(0);
        idx = vi(n);
        for(int i = 0; i < n; i++)
            idx[order[i]] = i;
        while(q--) 
        {
            cin >> p >> k; p--; k--;
            cout << (k >= sub[p]? -1 : order[idx[p]+k]+1) << '\n';
        }
    }
    return 0;
}