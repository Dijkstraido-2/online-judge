//============================================================================
// Problem  : 1077A - Frog Jumping
// Category : Basic
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int q;
    long long a,b,k;
    cin >> q;
    while(q--) {
        cin >> a >> b >> k;
        cout << a*(k/2+(k&1? 1:0)) - b*(k/2) << '\n';
    }
    return 0;
}