//============================================================================
// Problem  : 949B - A Leapfrog in the Array
// Category : Math
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(ll x, ll n) { return (x&1)? (x+1)/2 : solve(n + x/2, n); }

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n,x,q;
    while(cin >> n >> q)
    {
        while(q--)
        {
            cin >> x;
            cout << solve(x,n) << '\n';
        }
    }
    return 0;
}