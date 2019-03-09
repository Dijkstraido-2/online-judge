//============================================================================
// Problem  : ABC 121 C - Energy Drink Collector
// Category : Sortings
//============================================================================
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
struct store { ll p,t; };
 
inline bool operator < (const store &a, const store &b) {
    return (a.p != b.p)? a.p < b.p : a.t > b.t;
}
 
typedef vector<store> vs;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n,m;
    while(cin >> n >> m) {
        vs v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i].p >> v[i].t;
        }
        sort(v.begin(), v.end());
        ll ans = 0;
        for(int i = 0; i < n && m > 0; i++) {
            ll buy = min(m, v[i].t);
            ans += buy * v[i].p;
            m -= buy;
        }
        cout << ans << '\n';
    }
    return 0;
}