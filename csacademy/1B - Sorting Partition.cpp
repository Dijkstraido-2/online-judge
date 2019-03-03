//============================================================================
// Problem  : 1B - Sorting Partition
// Category : Greedy
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n),mn(n);
    for(int i = 0; i < n; i++) {
         cin >> v[i];
    }
    for(int i = n-1; i >= 0; i--) {
        mn[i] = min(i+1 < n? mn[i+1]:v[i], v[i]);
    }
    int ans = 0;
    for(int lo = 0; lo < n; lo++) {
        int hi = lo, a = v[lo];
        while(hi+1 < n && a > mn[hi+1]) {
            a = max(a, v[++hi]);
        } 
        lo = hi;
        ans++;
    }
    cout << ans << '\n';
    return 0;
}