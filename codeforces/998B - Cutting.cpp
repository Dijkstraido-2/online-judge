//============================================================================
// Problem  : 998B - Cutting
// Category : DP
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int v[105],n;
int dp[105][105][105];

int solve(int l, int r, int b)
{
    if(dp[l][r][b] != -1) return dp[l][r][b];
    int p[2] = {0,0}, q[2] = {0,0};
    for(int i = l; i < r; i++)
        q[(v[i]&1)? 1 : 0]++;
    int ans = 0;
    for(int i = l; i < r-1; i++)
    {
        p[(v[i]&1)? 1 : 0]++;
        if(p[0] == p[1] && b - abs(v[i]-v[i+1]) >= 0)
            ans = max(ans, 1 + solve(i+1,r,b - abs(v[i]-v[i+1])));
    }
    return dp[l][r][b] = ans;
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int b;
    while(cin >> n >> b)
    {
        for(int i = 0; i < n; i++)
            cin >> v[i];
        memset(dp, -1, sizeof dp);
        cout << solve(0,n-1,b) << '\n';
    }
    return 0;
}