//============================================================================
// Problem  : ARC 61 C - Many Formulas
// Category : Backtracking
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll ans;

void solve(string s, ll t) {
    if(s.empty()) {
        ans += t;
        return;
    }
    ll n = 0;
    for(int i = 0; i < (int)s.size(); i++) {
        n = n*10 + (s[i]-'0');
        solve(s.substr(i+1), t+n);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s;
    while(cin >> s) {
        ans = 0;
        solve(s, 0);
        cout << ans << '\n';
    }
    return 0;
}