//============================================================================
// Problem  : 77C - Two Rows
// Category : DP
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[2][100005][2][2];
ll memo[2][100005][2][2];
int n;
int M[2][100005];
const ll INF = 2000000000000000LL;

ll solve(int r, int c, int p, int t)
{
    if(c == n-1 && r == 1) return M[r][c];
    if(memo[r][c][p][t]) return dp[r][c][p][t];
    ll ans;
    if(t == 0)
    {
        if(p == 0)
            ans = M[r][c] + min(solve(1-r, c, 1, !t), c+1 < n? solve(r, c+1, 0, !t) : INF);
        else
            ans = M[r][c] + solve(r, c+1, 0, !t);
    }
    else
    {
        if(p == 0)
            ans = M[r][c] + max(solve(1-r, c, 1, !t), c+1 < n? solve(r, c+1, 0, !t) : -INF);
        else
            ans = M[r][c] + solve(r, c+1, 0, !t);
    }
    memo[r][c][p][t] = 1;
    return dp[r][c][p][t] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n)
    {
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < n; j++)
                cin >> M[i][j];
        memset(memo, 0, sizeof memo);
        cout << solve(0,0,0,0) << '\n';
    }
    return 0;
}