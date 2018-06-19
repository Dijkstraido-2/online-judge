//============================================================================
// Problem  : 992C - Nastya and a Wardrobe
// Category : Math
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9+7;

ll sub(ll a, ll b) { return (a%MOD - b%MOD + MOD) % MOD; }

ll mul(ll a, ll b) { return a%MOD * (b%MOD) % MOD; }

ll modP(ll b, ll p) { return !p? 1 : mul(modP(b*b%MOD, p/2), p&1? b:1); }

int main()
{
    ll x,k;
    while(cin >> x >> k)
    {
        if(x == 0)
            cout << 0 << '\n';
        else
            cout << sub(mul(modP(2, k+1), x), sub(modP(2, k), 1)) << '\n';
    }
    return 0;
}