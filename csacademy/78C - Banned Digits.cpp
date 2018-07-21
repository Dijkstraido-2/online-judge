//============================================================================
// Problem  : 78C - Banned Digits
// Category : DP on digits
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
int n;
ll dp[20][2][2];
int ban[12];

ll solve(int i, int f, int t) // pos, is less?, trailing zeros?
{
    if(i == n) return !ban[0]? (f == 1) : (f == 1 && !t);
    if(dp[i][f][t] != -1) return dp[i][f][t];
    ll ans = 0;
    for(int d = 0; d <= (f? 9 : (s[i]-'0')); d++)
        if(ban[d] == 0 || (d == 0 && t))
            ans += solve(i+1, f? 1 : (d < s[i]-'0'), !t? 0 : (d == 0));
    return dp[i][f][t] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long x;
    for(int i = 0; i < 10; i++)
        cin >> ban[i];
    cin >> x;
    s = to_string(x);
    n = s.size();
    memset(dp, -1, sizeof dp);    
    cout << solve(0, 0, 1) << '\n';
    return 0;
}