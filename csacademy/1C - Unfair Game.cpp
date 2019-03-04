//============================================================================
// Problem  : 1C - Unfair Game
// Category : DP
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> v,dp;
int n;

ll solve(int i) {
    if(i >= n) return 0;
    if(dp[i] != -1) return dp[i];
    return dp[i] = v[i] + max(solve(i+1), solve(i+2));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    v = vector<ll>(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    dp = vector<ll>(n,-1);
    cout << solve(0) << '\n';
    return 0;
}