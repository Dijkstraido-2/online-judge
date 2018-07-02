//============================================================================
// Problem  : 987C - Three displays
// Category : DP
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll dp[3005][3], cost[3005], sz[3005];
const ll INF = 20000000000000LL;

ll solve(int i, int c)
{
    if(i == n) return INF;
    if(c == 2) return cost[i];
    if(dp[i][c] != -1) return dp[i][c];
    ll ans = INF; 
    for(int j = i+1; j < n; j++)
        if(sz[i] < sz[j])
            ans = min(ans, cost[i] + solve(j, c+1));
    return dp[i][c] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n)
    {
        for(int i = 0; i < n; i++)
            cin >> sz[i];
        for(int i = 0; i < n; i++)
            cin >> cost[i];
        memset(dp, -1, sizeof dp);
        ll ans = INF;
        for(int i = 0; i < n; i++)
            ans = min(ans, solve(i, 0));
        cout << (ans == INF? -1 : ans) << '\n';
    }
    return 0;
}