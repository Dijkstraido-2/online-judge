//============================================================================
// Problem  : ARC 58 D - Iroha and a Grid
// Category : Combinatorics
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAX = 200005;
const ll MOD = 1000000007;

ll mul(ll a, ll b) { return a%MOD * (b%MOD) % MOD; }
ll modpow(ll b, ll p) { return !p? 1:mul(modpow(b*b%MOD, p/2), p&1? b:1); }
ll inv(ll a) { return modpow(a, MOD-2); }

ll fa[MAX], fi[MAX];

void init() {
    fa[0] = fi[0] = 1;
    for(ll i = 1; i < MAX; i++) {
        fa[i] = fa[i-1]*i % MOD;
        fi[i] = inv(fa[i]);
    } 
}

ll comb(ll n, ll k) { return fa[n] * fi[k] % MOD * fi[n-k] % MOD; }
ll solve(ll r, ll c) { return comb(r+c-2, r-1); }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    init();
    ll r,c,x,y;
    while(cin >> r >> c >> x >> y) {
        ll ans = 0;
        for(ll j = y+1; j <= c; j++)
            ans = (ans + solve(r-x, j)*solve(x, c-j+1)%MOD) % MOD;
        cout << ans << '\n';
    }
    return 0;
}