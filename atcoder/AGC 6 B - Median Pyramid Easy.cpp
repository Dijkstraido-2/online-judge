//============================================================================
// Problem  : AGC 6 B - Median Pyramid Easy
// Category : Ad hoc
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,x;
    while(cin >> n >> x) {
        if(x == 1 || x == 2*n - 1) {
            cout << "No" << '\n';
            continue;
        }
        cout << "Yes" << '\n';
        vector<int> v(2*n-1);
        int cont = 1;
        for(int i = 0; i < 2*n - 1; i++) {
            v[i] = (i == n-1)? x : cont++;
            if(cont == x)
                cont++;
        }
        reverse(v.begin(), v.begin()+n-1);
        reverse(v.begin()+n, v.end());
        for(auto x : v) {
            cout << x << '\n';
        }
    }
    return 0;
}