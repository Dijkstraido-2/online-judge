//============================================================================
// Problem  : 961B - Lecture Sleep
// Category : Prefix Sums
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vi v,p,dp1,dp2;
int n,k;

int s1(int l, int r) { return r < l? 0 : dp1[r+1] - dp1[l]; }
int s2(int l, int r) { return r < l? 0 : dp2[r+1] - dp2[l]; }

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> k)
    {
        v = vi(n);
        for(int i = 0; i < n; i++)
           cin >> v[i];
        p = vi(n);
        for(int i = 0; i < n; i++)
            cin >> p[i];
        dp1 = vi(n+1, 0); dp2 = vi(n+1, 0);
        for(int i = 0; i < n; i++)
        {
            dp1[i+1] = dp1[i] + v[i];
            dp2[i+1] = dp2[i] + (p[i]? v[i] : 0);
        }
        int ans = 0;
        for(int i = 0; i <= n-k; i++)
            ans = max(ans, s2(0,i-1) + s1(i,i+k-1) + s2(i+k,n-1));
        cout << ans << '\n';
    }
    return 0;
}