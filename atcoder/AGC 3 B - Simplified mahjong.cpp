//============================================================================
// Problem  : AGC 3 B - Simplified mahjong
// Category : Greedy
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(const vector<ll> &v) {
    ll n = v.size(), left = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        ll t = v[i]+left;
        ans += t/2;
        left = !v[i]? 0 : t%2;
    }
    return ans;
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin >> n) {
        vector<ll> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        cout << solve(v) << '\n';
    }
    return 0;
}