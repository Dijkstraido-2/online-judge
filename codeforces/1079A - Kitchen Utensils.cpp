//============================================================================
// Problem  : 1079A - Kitchen Utensils
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,k;
    map<int,int> fr;
    vi v;
    while(cin >> n >> k) {
        v = vi(n); fr.clear();
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            fr[v[i]]++;
        }
        int x = 0;
        for(auto p : fr)
            x = max(x, (int)ceil(p.second*1./k));
        int ans = 0;
        for(auto p : fr)
            ans += k*x - p.second;
        cout << ans << '\n';
    }
    return 0;
}