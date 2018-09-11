//============================================================================
// Judge    : 932B - Recursive Queries
// Category : DP (Partial Sums)
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int mul(int x)
{
    if(x < 10)
        return x;
    int ans = 1;
    while(x > 0)
    {
        int d = x % 10;
        if(d != 0)
            ans *= d;
        x /= 10;
    }
    return mul(ans);
}

const int MAX = 1000001;
int f[MAX];
int dp[MAX+5][10];

void init()
{
    memset(dp, 0, sizeof dp);
    for(int i = 1; i < MAX; i++)
    {
        f[i] = mul(i);
        dp[i][f[i]]++; 
    }

    for(int k = 1; k <= 9; k++)
        for(int i = 0; i < MAX; i++)
            dp[i+1][k] += dp[i][k];
}

int query(int k, int l, int r)
{
    return dp[r][k] - dp[l-1][k];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    init();
    int q,l,r,k;
    while(cin >> q)
    {
        while(q--)
        {
            cin >> l >> r >> k;
            cout << query(k, l, r) << '\n';
        }
    }
    return 0;
}