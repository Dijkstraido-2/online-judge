//============================================================================
// Problem  : 933A - A Twisty Movement
// Category : DP
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,dp[5];
    while(cin >> n)
    {
        memset(dp,0,sizeof dp);
        for(int i = 0; i < n; i++) 
        {
            int x; cin >> x; x--;
            for(int j = 1; j <= 4; j++)
                dp[j] = max(dp[j-1], dp[j] + (x != j%2));
        }
        cout << dp[4] << '\n';
    }
    return 0;
}