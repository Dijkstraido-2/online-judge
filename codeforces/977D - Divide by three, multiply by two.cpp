//============================================================================
// Problem  : 977D - Divide by three, multiply by two
// Category : Topsort
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vi> vvi;

vl v;
vi color,sorted;
vvi g;
int n;

void dfs(int v)
{
    color[v] = 1;
    for(int u : g[v])
        if(!color[u])
            dfs(u);
    sorted.push_back(v);
}

void topsort()
{
    color = vi(n, 0); sorted.clear();
    for(int i = 0; i < n; i++)
        if(!color[i])
            dfs(i);
    reverse(sorted.begin(), sorted.end());
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n)
    {
        v = vl(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        g = vvi(n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(i != j && (v[i]*2 == v[j] || (v[i]%3 == 0 && v[i]/3 == v[j])))
                    g[i].push_back(j);
        topsort();
        for(int i = 0; i < n; i++)
            cout << v[sorted[i]] << " \n"[i==n-1];
    }
    return 0;
}