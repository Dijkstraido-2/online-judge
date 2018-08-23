//============================================================================
// Problem  : 1025D - Recovering BST
// Category : DP
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int n,v[705],dp[705][705][2];

int solve(int l, int r, int mode) 
{
    if(r < l) return 1;
    if(dp[l][r][mode] != -1) return dp[l][r][mode];
    int ans = 0;
    for(int i = l; !ans && i <= r; i++)
        if(__gcd(v[i], (mode? v[l-1] : v[r+1])) != 1 && solve(l,i-1,0) && solve(i+1,r,1))
            ans = 1;
    return dp[l][r][mode] = ans;
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n)
    {
        for(int i = 0; i < n; i++)
            cin >> v[i];
        memset(dp, -1, sizeof dp);
        int ok = 0;
        for(int i = 0; !ok && i < n; i++)
            if(solve(0,i-1,0) && solve(i+1,n-1,1))
                ok = 1;
        cout << (ok? "Yes" : "No") << '\n';
    }
    return 0;
}