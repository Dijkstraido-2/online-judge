//============================================================================
// Problem  : 1020B - Badge
// Category : DFS
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vi p,color;

int dfs(int v)
{
    color[v] = 1;
    if(color[p[v]])
        return p[v];
    return dfs(p[v]);
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin >> n)
    {
        p = vi(n+1);
        for(int i = 1; i <= n; i++)
            cin >> p[i];
        for(int i = 1; i <= n; i++)
        {
            color = vi(n+1,0);
            cout << dfs(i) << " ";
        }
        cout << '\n';
    }
    return 0;
}