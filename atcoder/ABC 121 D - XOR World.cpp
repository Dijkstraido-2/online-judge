//============================================================================
// Problem  : ABC 121 D - XOR World
// Category : Math
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(ll x) {
    ll ans[4] = {x,1,x+1,0};
    return ans[x%4];
}

ll solve(ll a, ll b) { return a==0? f(b) : f(b)^f(a-1); }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll a,b;
    while(cin >> a >> b) {
        cout << solve(a,b) << '\n';
    }
    return 0;
}