//============================================================================
// Problem  : ABC 45 A - Trapezoids
// Category : Math
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a,b,h;
    while(cin >> a >> b >> h) {
        cout << (a+b)*h/2 << '\n';
    }
    return 0;
}