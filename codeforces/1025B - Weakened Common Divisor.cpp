//============================================================================
// Problem  : 1025B - Weakened Common Divisor
// Category : Prime Factorization + Brute force
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
const ll MAX = 1e6;

bitset<MAX> isprime; 
vector<ll> primes;  

void sieve() 
{ 
    isprime.set(); 
    isprime[0] = isprime[1] = 0; 
    for(ll i = 2; i < MAX; i++) 
        if(isprime[i]) 
        { 
            for(ll j = i*i; j < MAX; j += i) 
                isprime[j] = 0; 
            primes.push_back(i);
        } 
} 

vector<ll> primeFac(ll x) 
{ 
    vector<ll> pf; 
    ll p = primes[0], i = 1;    
    while(x != 1 && p*p <= x) 
    { 
        while(x % p == 0) { x /= p; pf.push_back(p); } 
        p = primes[i++]; 
    }     
    if(x != 1) pf.push_back(x); 
    return pf; 
} 

int n;
vi a,b,p;

int ok(ll x) 
{
    int cont = 0;
    for(int i = 0; i < n; i++)
        if(a[i] % x == 0 || b[i] % x == 0)
            cont++;
    return cont == n;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    sieve();
    while(cin >> n)
    {
        a = vi(n); b = vi(n);
        for(int i = 0; i < n; i++)
            cin >> a[i] >> b[i];
        ll ans = -1;
        p = primeFac(a[0]); 
        for(ll x : p)
            if(ok(x))
                ans = x;
        p = primeFac(b[0]);
        for(ll x : p)
            if(ok(x))
                ans = x;
        cout << ans << '\n';
    }
    return 0; 
}