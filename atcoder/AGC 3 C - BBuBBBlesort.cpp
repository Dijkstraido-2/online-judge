//============================================================================
// Problem  : AGC 3 C - BBuBBBlesort
// Category : Greedy
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin >> n) {
        vector<int> v(n);
        map<int,int> parity;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            parity[v[i]] = 0;
        }
        int f = 0;
        for(auto &it : parity) {
            it.second = f;
            f = !f;
        }
        int cont = 0;
        for(int i = 0; i < n; i++) {
            if((i&1) != parity[v[i]])
                cont++;
        }
        cout << cont/2 << '\n';
    }
    return 0;
}