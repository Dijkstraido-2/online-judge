//============================================================================
// Judge    : 920E - Connected Components
// Category : DFS
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef set<int> si;
typedef vector<int> vi;
typedef vector<si> vsi;

si unvisited;
vsi g;
int n,sz;

void dfs(int v)
{
    unvisited.erase(v);
    sz++;
    int cur = -1;
    while(cur < n)
    {
        auto it = unvisited.upper_bound(cur);
        if(it == unvisited.end())
            break;
        cur = *it;
        if(!g[v].count(cur))
            dfs(cur);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int m,x,y;
    vi ans;
    while(cin >> n >> m)
    {
        g = vsi(n);
        for(int i = 0; i < m; i++)
        {
            cin >> x >> y; x--; y--;
            g[x].insert(y);
            g[y].insert(x);
        }
        unvisited.clear();
        for(int i = 0; i < n; i++)
            unvisited.insert(i);
        ans = vi();
        for(int i = 0; i < n; i++)
            if(unvisited.count(i))
            {
                sz = 0;
                dfs(i);
                ans.push_back(sz);
            }
        sort(ans.begin(), ans.end());
        cout << (int)ans.size() << '\n';
        for(int x : ans)
            cout << " " << x;
        cout << '\n';
    }
    return 0;
}