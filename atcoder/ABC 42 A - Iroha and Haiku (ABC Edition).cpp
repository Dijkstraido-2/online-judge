//============================================================================
// Problem  : ABC 42 A - Iroha and Haiku (ABC Edition)
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int v[3];
    while(cin >> v[0] >> v[1] >> v[2]) {
        sort(v, v+3);
        cout << (v[0] == 5 && v[1] == 5 && v[2] == 7? "YES" : "NO") << '\n';
    }
    return 0;
}