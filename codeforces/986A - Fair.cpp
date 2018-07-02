//============================================================================
// Problem  : 986A - Fair
// Category : BFS
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;

int n,k,s;
vvi g;
vi pr;
int dis[100005][105];
queue<iii> pq;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int m,x,y;
    while(cin >> n >> m >> k >> s)
    {
        pr = vi(n); 
        for(int i = 0; i < n; i++)
            cin >> pr[i], pr[i]--;
        g = vvi(n);
        for(int i = 0; i < m; i++)
        {
            cin >> x >> y; x--; y--;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < k; j++)
                dis[i][j] = 2e8;
        for(int i = 0; i < n; i++)
        {
            pq.push({{0, i}, pr[i]});
            dis[i][pr[i]] = 0;
        }
        while(!pq.empty())
        {
            iii top = pq.front(); pq.pop();
            int d = top.first.first;
            int v = top.first.second;
            int p = top.second;
            if(d > dis[v][p]) continue;
            for(int u : g[v])
                if(d + 1 < dis[u][p])
                {
                    dis[u][p] = d + 1;
                    pq.push({{d+1, u}, p});
                }
        }
        for(int i = 0; i < n; i++)
        {
            sort(dis[i], dis[i] + k);
            int ans = 0;
            for(int j = 0; j < s; j++)
                ans += dis[i][j];
            cout << ans << " ";
        }
        cout << '\n';
    }
    return 0;
}