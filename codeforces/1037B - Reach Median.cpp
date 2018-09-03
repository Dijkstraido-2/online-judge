//============================================================================
// Problem  : 1037B - Reach Median
// Category : Greedy + Sort
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n,s;
    vi v;
    while(cin >> n >> s)
    {
        v = vi(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        ll ans = 0;
        for(int i = 0; i < n/2; i++)
            ans += max(v[i]-s, 0ll);
        ans += labs(v[n/2]-s);
        for(int i = n/2+1; i < n; i++)
            ans += max(s-v[i], 0ll);
        cout << ans << '\n';
    }
    return 0;
}