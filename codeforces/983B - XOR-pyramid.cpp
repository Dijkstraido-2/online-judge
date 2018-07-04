//============================================================================
// Problem  : 983B - XOR-pyramid
// Category : DP
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int dp[5005][5005],v[5005][5005],n,q,l,r;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n)
    {
        memset(v, 0, sizeof v); memset(dp, 0, sizeof dp);
        for(int i = 0; i < n; i++)
        {
            cin >> v[0][i];
            dp[0][i] = v[0][i];
        }
        for(int i = 1; i < n; i++)
            for(int j = 0; j < n-i; j++)
            {
                v[i][j] = v[i-1][j] ^ v[i-1][j+1];
                dp[i][j] = max(v[i][j], max(dp[i-1][j], dp[i-1][j+1]));
            }
        cin >> q;
        while(q--)
        {
            cin >> l >> r; l--; r--;
            cout << dp[r-l][l] << '\n';
        }
    }
    return 0;
}