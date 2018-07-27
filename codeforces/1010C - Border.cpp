//============================================================================
// Problem  : 1010C - Border
// Category : Number Theory
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) { return !b? a : gcd(b, a%b); }

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n,k,g,x;
    set<ll> st;
    while(cin >> n >> k)
    {
        g = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            g = gcd(g, x%k);
        }
        st.clear();
        for(ll i = 1; i <= k; i++)
            st.insert(g*i % k);
        cout << st.size() << '\n';
        for(ll p : st)
            cout << " " << p;
        cout << '\n';
    }
    return 0;
}