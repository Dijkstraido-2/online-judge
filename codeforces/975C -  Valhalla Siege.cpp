//============================================================================
// Problem  : 975C -  Valhalla Siege
// Category : Binary Search
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,v[200005],dp[200005];

ll sum(ll l, ll r) { return dp[r+1] - dp[l]; }

ll solve(ll ori, ll k)
{
    ll lo = ori, hi = n-1, mid;
    while(lo < hi)
    {
        mid = lo + (hi-lo+1)/2;
        if(sum(ori,mid) <= k)
            lo = mid;
        else
            hi = mid - 1;
    }
    return lo;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll s,x,l,r,q;
    while(cin >> n >> q)
    {
        memset(dp, 0, sizeof dp);
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
            dp[i+1] = dp[i] + v[i];
        }
        s = l = 0;
        while(q--)
        {
            cin >> x;
            s += x;
            if(s >= v[l])
            {
                r = solve(l, s);
                if(r == n - 1)
                    l = s = 0;
                else
                {
                    s -= sum(l,r);
                    l = r + 1;
                }
            }
            cout << n - l << '\n';
        }
    }
    return 0;
}