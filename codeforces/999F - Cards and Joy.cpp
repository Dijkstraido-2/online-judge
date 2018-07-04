//============================================================================
// Problem  : 999F - Cards and Joy
// Category : DP
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

const int MAX = 100001;
ll n,k,dp[505][5005];
vi t,f,h;

ll solve(int a, int b) // Optimally distribute "b" cards between "a" people
{
    if(a == 0) return 0;
    if(dp[a][b] != -1) return dp[a][b];
    ll ans = 0;
    for(int i = 0; i <= k; i++)
        if(b-i >= 0)
            ans = max(ans, h[i] + solve(a-1, b-i));
    return dp[a][b] = ans; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int x;
    while(cin >> n >> k)
    {
        t = vi(MAX, 0);
        for(int i = 0; i < n*k; i++) { cin >> x; t[x]++; }
        f = vi(MAX, 0);
        for(int i = 0; i < n; i++)  { cin >> x; f[x]++; }
        h = vi(k+1,0);
        for(int i = 1; i <= k; i++)
            cin >> h[i];
        memset(dp, -1, sizeof dp);
        ll ans = 0;
        for(int c = 1; c < MAX; c++)
            ans += solve(f[c], t[c]);
        cout << ans << '\n';
    }
    return 0;
}