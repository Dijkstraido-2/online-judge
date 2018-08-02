//============================================================================
// Problem  : 915G - Coprime Arrays
// Category : Inclusion-Exclusion
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

const ll MAX = 2e6+5;
const ll MOD = 1e9+7;

bitset<MAX> bs;
vi pf[MAX];

void sieve() 
{
    bs.set(); bs[0] = bs[1] = 0;
    for(ll i = 2; i < MAX; i++)
        if(bs[i])
            for(ll j = i*i; j < MAX; j += i)
                bs[j] = 0;
    for(ll i = 2; i < MAX; i++)
        if(bs[i])
            for(ll j = i; j < MAX; j += i)
                pf[j].push_back(i);
}

ll mul(ll a, ll b) { return a%MOD * (b%MOD) % MOD; }
ll po(ll b, ll p) { return !p? 1 : mul(po(b*b%MOD, p/2), p&1? b:1); }

ll pot[MAX],cur;

void solve(ll n, ll pos, ll prod, ll t)
{
    if(pos == pf[n].size()) 
    {
        cur += t*pot[n/prod] - t*pot[n/prod - 1];
        return;
    }
    solve(n, pos+1, prod*pf[n][pos], -t);
    solve(n, pos+1, prod, t);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    sieve();
    ll n,k,ans=0;
    cin >> n >> k;
    for(int i = 0; i < MAX; i++)
        pot[i] = po(i,n);
    for(int i = 1; i <= k; i++)
    {
        solve(i,0,1,1);
        cur = (cur%MOD + MOD)%MOD;
        ans += cur^i;
    }
    cout << ans%MOD << '\n';
    return 0;
}