//============================================================================
// Problem  : 978F - Mentors
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi g;
vii v;
int n;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int m,x,y;
    vi ans;
    unordered_set<int> ht;
    while(cin >> n >> m)
    {
        v = vii(n);
        for(int i = 0; i < n; i++)
        {
            cin >> v[i].first;
            v[i].second = i;
        }
        g = vvi(n);
        for(int i = 0; i < m; i++)
        {
            cin >> x >> y; x--; y--;
            if(v[y].first < v[x].first)
                g[x].push_back(y);
            if(v[x].first < v[y].first)
                g[y].push_back(x);
        }
        sort(v.begin(), v.end());
        ht.clear(); int rep = 0;
        ans = vi(n);
        for(int i = 0; i < n; i++)
        {
            if(i > 0 && v[i].first == v[i-1].first)
                rep++;
            else
                rep = 1;
            int cont = i+1 - rep;
            for(int u : g[v[i].second])
                if(ht.find(u) != ht.end())
                    cont--;
            ans[v[i].second] = cont;
            ht.insert(v[i].second);
        }
        for(int x : ans)
            cout << x << " ";
        cout << '\n';
    }
    return 0;
}