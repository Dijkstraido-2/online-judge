//============================================================================
// Problem  : ARC 60 C - Tak and Cards
// Category : DP
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> v;
ll n,a,dp[55][2505][55];

ll solve(int i, int s, int t) {
    if(i == n) return t > 0 && s%t == 0 && s/t == a;
    if(dp[i][s][t] != -1) return dp[i][s][t];
    return dp[i][s][t] = solve(i+1, s+v[i], t+1) + solve(i+1, s, t);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> a) {
        v = vector<ll>(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        memset(dp, -1, sizeof dp);
        cout << solve(0,0,0) << '\n';
    }
    return 0;
}