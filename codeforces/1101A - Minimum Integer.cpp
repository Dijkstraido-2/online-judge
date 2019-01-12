//============================================================================
// Problem  : 1101A - Minimum Integer
// Category : Math
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll q,l,r,d,lo,hi;
    cin >> q;
    while(q--) {
        cin >> l >> r >> d;
        lo = ceil(l*1./d);
        hi = floor(r*1./d);
        cout << d*(lo <= 1? hi+1 : 1) << '\n'; 
    }
    return 0;
}