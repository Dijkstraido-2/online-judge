//============================================================================
// Problem  : ABC 46 B - Painting Balls with AtCoDeer
// Category : Math
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,k;
    while(cin >> n >> k) {
        int ans = k;
        for(int i = 1; i < n; i++) {
            ans *= k-1;
        }
        cout << ans << '\n';
    }
    return 0;
}