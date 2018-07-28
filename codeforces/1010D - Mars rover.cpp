//============================================================================
// Problem  : 1010D - Mars rover
// Category : DFS
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

vvi g;
int n,x,y;
vi f,r;
vs s;

void dfs(int v) 
{
    for(int u : g[v])
        dfs(u);
    if(s[v] == "AND")
        f[v] = f[g[v][0]] & f[g[v][1]];
    else if(s[v] == "OR")
        f[v] = f[g[v][0]] | f[g[v][1]];
    else if(s[v] == "XOR")
        f[v] = f[g[v][0]] ^ f[g[v][1]];
    else if(s[v] == "NOT")
        f[v] = !f[g[v][0]];
}

void rev(int v) 
{
    if(!r[v]) 
        return;
    if(s[v] == "AND") 
    {
        x = (!f[g[v][0]]) & (f[g[v][1]]);
        if(x != f[v])
            r[g[v][0]] = 1;
        x = (f[g[v][0]]) & (!f[g[v][1]]);
        if(x != f[v])
            r[g[v][1]] = 1;
    }
    else if(s[v] == "OR") 
    {
        x = (!f[g[v][0]]) | (f[g[v][1]]);
        if(x != f[v])
            r[g[v][0]] = 1;
        x = (f[g[v][0]]) | (!f[g[v][1]]);
        if(x != f[v])
            r[g[v][1]] = 1;
    }
    else if(s[v] == "XOR") 
        r[g[v][0]] = r[g[v][1]] = 1;
    else if(s[v] == "NOT") 
        r[g[v][0]] = 1;

    for(int u : g[v])
        rev(u);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n)
    {
        g = vvi(n); s = vs(n); f = vi(n); r = vi(n,0); 
        for(int i = 0; i < n; i++)
        {
            cin >> s[i];
            if(s[i] == "IN") 
                cin >> f[i]; 
            else if(s[i] == "NOT") 
            {
                cin >> x; x--;
                g[i].push_back(x);
            }
            else 
            {
                cin >> x >> y; x--; y--;
                g[i].push_back(x);
                g[i].push_back(y);
            }
        }
        dfs(0);
        r[0] = 1; rev(0);
        for(int i = 0; i < n; i++)
            if(s[i] == "IN")
                cout << (f[0] ^ r[i]);
        cout << '\n';
    }
    return 0;
}