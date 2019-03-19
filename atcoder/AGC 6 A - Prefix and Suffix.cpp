//============================================================================
// Problem  : AGC 6 A - Prefix and Suffix
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    string s,t;
    while(cin >> n >> s >> t) {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(s.substr(n-i,i) == t.substr(0,i)) {
                ans = i;
            }
        }
        cout << 2*n - ans << '\n';
    }
    return 0;
}