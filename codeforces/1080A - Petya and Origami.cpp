//============================================================================
// Problem  : 1080A - Petya and Origami
// Category : Simple Math
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n,k;
    while(cin >> n >> k)
        cout << (ll)(ceil(n*2./k) + ceil(n*5./k) + ceil(n*8./k)) << '\n';
    return 0;
}