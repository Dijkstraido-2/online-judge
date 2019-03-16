//============================================================================
// Problem  : AGC 4 A - Divide a Cuboid
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline ll f(ll x) { return ll(floor(x/2.)); }
inline ll c(ll x) { return ll(ceil(x/2.)); }
inline ll min3(ll a, ll b, ll c) { return min(a, min(b,c)); } 

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll x,y,z;
    while(cin >> x >> y >> z) {
        cout << min3(llabs(x*y*f(z) - x*y*c(z)), 
                     llabs(x*f(y)*z - x*c(y)*z),
                     llabs(f(x)*y*z - c(x)*y*z)) << '\n';
    }
    return 0;
}