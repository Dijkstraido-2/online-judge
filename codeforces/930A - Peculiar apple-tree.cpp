//============================================================================
// Judge    : 930A - Peculiar apple-tree
// Category : DFS
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi g;
int n;
vi p;

void dfs(int v, int h = 0)
{
    p[h] ^= 1;
    for(int u : g[v])
        dfs(u, h+1);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int x,ans;
    while(cin >> n)
    {
        g = vvi(n);
        for(int y = 1; y < n; y++)
        {
            cin >> x; x--;
            g[x].push_back(y);
        }
        p = vi(n, 0);
        dfs(0);
        ans = 0;
        for(int x : p)
            ans += x;
        cout << ans << '\n';
    }
    return 0;
}