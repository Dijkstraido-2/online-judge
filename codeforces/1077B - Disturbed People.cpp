//============================================================================
// Problem  : 1077B - Disturbed People
// Category : Greedy
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    vector<int> v;
    while(cin >> n) {
        v = vector<int>(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        int ans = 0;
        for(int i = 1; i < n-1; i++)
            if(v[i-1] == 1 && v[i] == 0 && v[i+1] == 1) {
                ans++;
                v[i+1] = 0;
            }
        cout << ans << '\n';
    }
    return 0;
}