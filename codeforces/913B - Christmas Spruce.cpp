//============================================================================
// Problem  : 913B - Christmas Spruce
// Category : DFS, Basic
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi g;
int n;
bool ans;

int dfs(int v)
{
    if(g[v].empty())
        return 1;
    int cont = 0;
    for(int u : g[v])
        cont += dfs(u);
    if(cont <= 2)
        ans = false;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int x;
    while(cin >> n)
    {
        g = vvi(n);
        for(int y = 1; y < n; y++)
        {
            cin >> x; x--;
            g[x].push_back(y);
        }
        ans = true;
        dfs(0);
        cout << (ans? "Yes" : "No") << '\n';
    }
    return 0;
} 