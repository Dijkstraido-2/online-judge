//============================================================================
// Judge    : 917B/918D - MADMAX
// Category : DP
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vvii g;
int n;
int dp[105][105][27];

int solve(int i, int j, int c)
{
    if(dp[i][j][c] != -1) return dp[i][j][c];
    for(ii nxt : g[i])
    {
        int u = nxt.second, w = nxt.first;
        if(w >= c && !solve(j, u, w))
            return dp[i][j][c] = 1;
    }
    return dp[i][j][c] = 0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int m,x,y,w;
    char c;
    while(cin >> n >> m)
    {
        g = vvii(n);
        for(int i = 0; i < m; i++)
        {
            cin >> x >> y >> c; x--; y--;
            w = c - 'a' + 1;
            g[x].push_back({w,y});
        }
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
               cout << (solve(i,j,0)? "A" : "B");
            cout << '\n';
        }
    }
    return 0;
} 