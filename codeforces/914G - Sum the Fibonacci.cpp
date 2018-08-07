//============================================================================
// Problem  : 914G - Sum the Fibonacci
// Category : FFT
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll MOD = 1000000007;
const ll MAX = 1<<17;

int nxtPowerOf2(int x) { return x<=1? 1:(1 << (32-__builtin_clz(x-1))); }

namespace andConv {
    vl andConv(vl P, bool inv = 0) {
        for(int len = 1; 2*len <= (int)P.size(); len <<= 1) {
            for(int i = 0; i < (int)P.size(); i += 2*len) {
                for(int j = 0; j < len; j++) {
                    ll u = P[i+j];
                    ll v = P[i+len+j];
                    if(!inv) {
                        P[i+j] = v;
                        P[i+len+j] = (u+v) % MOD;
                    } else {
                        P[i+j] = (v-u+MOD) % MOD;
                        P[i+len+j] = u;
                    }
                }
            }
        }
        return P;
    }
    
    vl conv(vl a, vl b) {
        int s = max(a.size(), b.size()), n = nxtPowerOf2(s);
        if(s <= 0) return {};
        a.resize(n); a = andConv(a);
        b.resize(n); b = andConv(b);
        for(int i = 0; i < n; i++) a[i] = a[i]*b[i] % MOD;
        a = andConv(a,1);
        return a;
    }
}

namespace orConv {
    vl andConv(vl P, bool inv = 0) {
        for(int len = 1; 2*len <= (int)P.size(); len <<= 1) {
            for(int i = 0; i < (int)P.size(); i += 2*len) {
                for(int j = 0; j < len; j++) {
                    ll u = P[i+j];
                    ll v = P[i+len+j];
                    if(!inv) {
                        P[i+j] = (u+v) % MOD;
                        P[i+len+j] = u;
                    } else {
                        P[i+j] = v;
                        P[i+len+j] = (u-v+MOD) % MOD;
                    }
                }
            }
        }
        return P;
    }
    
    vl conv(vl a, vl b) {
        int s = max(a.size(), b.size()), n = nxtPowerOf2(s);
        if(s <= 0) return {};
        a.resize(n); a = andConv(a);
        b.resize(n); b = andConv(b);
        for(int i = 0; i < n; i++) a[i] = a[i]*b[i] % MOD;
        a = andConv(a,1);
        return a;
    }
}

namespace xorConv { 
    ll modpow(ll b, ll p) { return !p?1:modpow(b*b%MOD,p/2)*(p&1?b:1)%MOD; }
    ll inv(ll b) { return modpow(b,MOD-2); }
    
    vl fwht(vl P) {
        for(int len = 1; 2*len <= (int)P.size(); len <<= 1) {
            for(int i = 0; i < (int)P.size(); i += 2*len) {
                for (int j = 0; j < len; j++) {
                    ll u = P[i+j];
                    ll v = P[i+len+j];
                    P[i+j] = (u+v)%MOD;
                    P[i+len+j] = (u-v+MOD)%MOD;
                }
            }
        }
        return P;
    }

    vl fwht_rev(vl& a) {
        vl res = fwht(a);
        ll x = inv(a.size());
        for(int i = 0; i < (int)res.size(); i++) 
            res[i] = res[i]*x % MOD;
        return res;
    }
    
    vl conv(vl a, vl b) {
        int s = max(a.size(), b.size()), n = nxtPowerOf2(s);
        if(s <= 0) return {};
        a.resize(n); a = fwht(a);
        b.resize(n); b = fwht(b);
        for(int i = 0; i < n; i++) a[i] = a[i]*b[i] % MOD;
        a = fwht_rev(a);
        return a;
    }
}

int n;
vl fr,fib(MAX,0);
vl ret;

void go(int pos, int mask, vi& t, int res) 
{
    if(pos == (int)t.size())
    {
        ret[mask|res] += fr[mask]*fr[res];
        ret[mask|res] %= MOD;
        return;
    }
    go(pos+1,mask,t,res);
    go(pos+1,mask,t,res^(1<<t[pos]));
}

vl subsetConv() 
{
    ret = vl(1<<17,0);
    for(int mask = 0; mask < MAX; mask++) 
    {
        vi t;
        for(int i = 0; i < 17; i++) 
            if(!(mask & (1<<i)))
                t.push_back(i);
        go(0,mask,t,0);
    }
    return ret;
}

vl trans(vl p) 
{
    for(int i = 0; i < (int)p.size(); i++) 
        p[i] = p[i]*fib[i] % MOD;
    return p;
}

void init() 
{
    fib[1] = 1;
    for(int i = 2; i < MAX; i++) 
        fib[i] = (fib[i-1]+fib[i-2]) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    init();
    int x;
    while(cin >> n) 
    {
        fr = vl(MAX, 0);
        for(int i = 0; i < n; i++) 
        {
            cin >> x;
            fr[x]++;
        }
        vl a = trans(subsetConv());
        vl b = trans(fr);
        vl c = trans(xorConv::conv(fr,fr));
        vl g = andConv::conv(a,andConv::conv(b,c));
        ll ans = 0;
        for(int i = 0; i < 17; i++) 
            ans = (ans+g[1<<i]) % MOD;
        cout << ans << '\n';
    }
    return 0; 
}