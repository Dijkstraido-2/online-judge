//============================================================================
// Problem  : AGC 1 A - BBQ Easy
// Category : Sortings
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin >> n) {
        vector<int> v(2*n);
        for(int i = 0; i < 2*n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int ans = 0;
        for(int i = 0; i < 2*n; i += 2) {
            ans += v[i];
        }
        cout << ans << '\n';
    }
    return 0;
}