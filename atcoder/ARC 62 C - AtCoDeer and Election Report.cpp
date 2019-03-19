//============================================================================
// Problem  : ARC 62 C - AtCoDeer and Election Report
// Category : Math
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline ll ceill(ll a, ll b) { return a/b + (a%b != 0); }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin >> n) {
        ll a = 1, b = 1;
        for(int i = 0; i < n; i++) {
            ll x, y; cin >> x >> y;
            ll k = max(ceill(a,x), ceill(b,y));
            a = x*k; b = y*k;
        }
        cout << a+b << '\n';
    }
    return 0;
}