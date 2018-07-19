//============================================================================
// Problem  : 84B - Three Ones
// Category : Binary Search
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int n,dp[500005];
string s;

int get(int l, int r) { return dp[r+1] - dp[l]; }

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> s;
    for(int i = 0; i < n; i++)
        dp[i+1] = dp[i] + (s[i] == '1');
    int ans = 3;
    for(int i = 0; i <= n-3; i++)
    {
        int lo = i, hi = n-1, mid;
        while(lo < hi) {
            mid = lo + (hi-lo)/2;
            if(get(i, mid) >= 3)
                hi = mid;
            else
                lo = mid+1;
        }
        if(get(i, lo) >= 3)
            ans = max(ans, lo-i+1);
        else
            ans = max(ans, n-i+1);
    }
    cout << ans << '\n';
    return 0;
}