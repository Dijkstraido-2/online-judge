//============================================================================
// Problem  : 1037C - Equalize
// Category : DP
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int dp[1000005],n;
string s,t;

int solve(int pos)
{
    if(pos == n) return 0;
    if(dp[pos] != -1) return dp[pos];

    int ans = (s[pos] == t[pos]? 0 : 1) + solve(pos+1);
    if(pos+1 < n && s[pos] != t[pos] && s[pos] == t[pos+1] && s[pos+1] == t[pos])
        ans = min(ans, 1 + solve(pos+2));
    return dp[pos] = ans; 
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> s >> t)
    {
        memset(dp, -1, sizeof dp);
        cout << solve(0) << '\n';
    }
    return 0;
}