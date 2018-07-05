//============================================================================
// Problem  : 991D - Bishwock
// Category : DP
//============================================================================
#include <bits/stdc++.h>
using namespace std;

string M[2];
int n,dp[105][4];

int solve(int c, int p)
{
    if(c >= n-1) return 0;
    if(dp[c][p] != -1) return dp[c][p];
    int ans = solve(c+1,0);
    if(p == 0 && M[0][c] == '0' && M[1][c] == '0' && M[0][c+1] == '0')
        ans = max(ans, 1 + solve(c+1,1));
    if((p == 0 || p == 3) && M[0][c] == '0' && M[0][c+1] == '0' && M[1][c+1] == '0')
        ans = max(ans, 1 + solve(c+1,2));
    if((p == 0 || p == 1) && M[1][c] == '0' && M[0][c+1] == '0' && M[1][c+1] == '0')
        ans = max(ans, 1 + solve(c+1,2));
    if(p == 0 && M[0][c] == '0' && M[1][c] == '0' && M[1][c+1] == '0')
        ans = max(ans, 1 + solve(c+1,3));
    return dp[c][p] = ans;
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> M[0] >> M[1])
    {
        n = M[0].size(); memset(dp, -1, sizeof dp);
        cout << solve(0,0) << '\n'; 
    }
    return 0;
}