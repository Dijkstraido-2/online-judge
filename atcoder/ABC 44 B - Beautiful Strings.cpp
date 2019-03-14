//============================================================================
// Problem  : ABC 44 B - Beautiful Strings
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s;
    while(cin >> s) {
        vector<int> f(26,0);
        for(char c : s) {
            f[c-'a']++;
        }
        int ok = 1;
        for(int i = 0; i < 26 && ok; i++) {
            if(f[i] % 2 != 0) {
                ok = 0;
            }
        }
        cout << (ok? "Yes" : "No") << '\n';
    }
    return 0;
}