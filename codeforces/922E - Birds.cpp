//============================================================================
// Judge    : CF 922E - Birds
// Category : DP
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,w,b,x,m,ans;
ll t[1005],c[1005],dp[1005][10005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> w >> b >> x)
    {
        m = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> t[i];
            m += t[i];
        }
        for(int i = 1; i <= n; i++)
            cin >> c[i];
        memset(dp, -1, sizeof dp);
        dp[0][0] = w; ans = 0;
        for(int i = 1; i <= n; i++)
            for(ll j = 0; j <= m; j++)
                for(ll k = 0; k <= min(j,t[i]); k++)
                    if(dp[i-1][j-k] >= 0)
                    {
                        ll best = min(w + (j-k)*b, dp[i-1][j-k] + x) - c[i]*k;
                        if(best < 0)
                            continue;
                        dp[i][j] = max(dp[i][j], best);
                        ans = max(ans, j);
                    }
        cout << ans << '\n';
    }
    return 0;
}