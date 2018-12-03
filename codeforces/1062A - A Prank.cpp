//============================================================================
// Problem  : 1062A - A Prank
// Category : Brute force
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
        int ans = 0, cont = 0;
        for(int i = 0; i < n; i++) {
            if(i == 0 && i+1 < n && v[i+1] == 2)
                cont++;
            else if(i == n-1 && i-1 >= 0 && v[i-1] == 999)
                cont++;
            else if(i-1 >= 0 && i+1 < n && v[i-1]+1 == v[i] && v[i] == v[i+1]-1)
                cont++;
            else
                cont = 0;
            ans = max(ans, cont);
        }
        cout << ans << '\n';
    }
    return 0;
}