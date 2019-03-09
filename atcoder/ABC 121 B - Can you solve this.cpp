//============================================================================
// Problem  : ABC 121 B - Can you solve this
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;
 
typedef vector<int> vi;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,c;
    while(cin >> n >> m >> c) {
        vi b(m);
        for(int i = 0; i < m; i++) {
            cin >> b[i];
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int s = c;
            for(int i = 0; i < m; i++) {
                int a; cin >> a;
                s += a*b[i];
            }
            ans += (s > 0);
        }
        cout << ans << '\n';
    }
    return 0;
}