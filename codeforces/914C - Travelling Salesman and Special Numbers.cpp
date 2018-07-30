//============================================================================
// Problem  : 914C - Travelling Salesman and Special Numbers
// Category : DP
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = (ll)1e9+7;
const int MAX = 1005;
string s;
int n,k;
ll dp[MAX][2][MAX];
int memo[MAX];

int numSteps(int x)
{
    if(x == 1) return 0;
    return 1 + numSteps(__builtin_popcount(x));
}

void init()
{
    for(int i = 1; i <= 1000; i++)
        memo[i] = numSteps(i) + 1;
}

ll solve(int i, int f, int on)
{
    if(i == n - 1 && !on) return k == 0;
    if(i == n - 1 && (f || s[i] == '1')) return (memo[on] == k) + (memo[on+1] == k);
    if(i == n - 1) return (memo[on] == k);
    if(dp[i][f][on] != -1) return dp[i][f][on];
    int ans = 0;
    for(int d = 0; d <= (f? 1 : s[i] - '0'); d++)
        ans = (ans + solve(i+1, f? 1 : (d < s[i] - '0'), on + (d == 1))) % MOD;
    return dp[i][f][on] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    init();
    while(cin >> s >> k)
    {
        n = s.size();
        memset(dp, -1, sizeof dp);
        cout << solve(0,0,0) << '\n';
    }
    return 0;
}