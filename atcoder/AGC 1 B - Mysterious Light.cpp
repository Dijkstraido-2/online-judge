//============================================================================
// Problem  : AGC 1 B - Mysterious Light
// Category : Math
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) { return !b? a : gcd(b, a%b); }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n,x;
    while(cin >> n >> x) {
        cout << 3*(n - gcd(n,x)) << '\n';
    }
    return 0;
}