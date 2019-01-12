//============================================================================
// Problem  : 1101E - Polycarps New Job
// Category : Greedy
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int q,x,y,w=0,h=0;
    char opc;
    cin >> q;
    while(q--) {
        cin >> opc >> x >> y;
        if(x > y)
            swap(x,y);
        if(opc == '+') {
            w = max(w, x);
            h = max(h, y);
        } else {
            cout << (w <= x && h <= y? "YES" : "NO") << '\n';
        }
    }
    return 0;
}