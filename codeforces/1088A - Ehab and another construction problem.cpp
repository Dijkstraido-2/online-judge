//============================================================================
// Problem  : 1088A - Ehab and another construction problem
// Category : Basic Programming
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int x;
    while(cin >> x) {
        if(x == 1)
            cout << -1 << '\n';
        else
            cout << x << " " << x << '\n'; 
    }
    return 0;
}