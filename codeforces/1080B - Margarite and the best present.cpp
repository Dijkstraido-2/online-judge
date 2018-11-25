//============================================================================
// Problem  : 1080B - Margarite and the best present
// Category : Math
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll sumEven(ll n) { return n/2*(n/2+1); }
ll sumEven(ll l, ll r) { return sumEven(r) - sumEven(l-2); }

ll sumOdd(ll n) { return ((n+1)/2)*((n+1)/2); }
ll sumOdd(ll l, ll r) { return sumOdd(r) - sumOdd(l-2); }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int q;
    ll l,r;
    cin >> q;
    while(q--) {
        cin >> l >> r;
        cout << -sumOdd(l%2? l:l+1, r%2? r:r-1) + sumEven(l%2?l+1:l, r%2? r-1:r) << '\n';
    }
    return 0;
}