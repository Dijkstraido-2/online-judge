//============================================================================
// Problem  : 1005D - Polycarp and Div 3
// Category : DP
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
string t;
ll n,dp[3][200005];

ll solve(int s, int i) // (sum, pos)
{
    if(i == n-1) return !s;
    if(dp[s][i] != -1) return dp[s][i];
    return dp[s][i] = max(solve((s+t[i+1]-'0')%3,i+1), !s + solve((t[i+1]-'0')%3,i+1));
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> t)
    {
        n = t.size(); memset(dp, -1, sizeof dp);
        cout << solve((t[0]-'0')%3,0) << '\n';
    }
    return 0;
}