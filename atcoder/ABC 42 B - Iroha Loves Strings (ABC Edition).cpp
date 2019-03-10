//============================================================================
// Problem  : ABC 42 B - Iroha Loves Strings (ABC Edition)
// Category : Sorting
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,l;
    while(cin >> n >> l) {
        vector<string> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        for(auto s : v) {
            cout << s;
        }
        cout << '\n';
    }
    return 0;
}