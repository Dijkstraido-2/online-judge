//============================================================================
// Problem  : 983A - Finite or not
// Category : Math
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) { return !b? a : gcd(b, a%b); }

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int q;
    ll x,y,b,g;
    cin >> q;
    while(q--)
    {
        cin >> x >> y >> b;
        g = gcd(x,y);
        y /= g;
        while((g = gcd(y,b)) != 1)
            while(y % g == 0) 
                y /= g;
        cout << (y == 1? "Finite" : "Infinite") << '\n';
    }
    return 0;
}