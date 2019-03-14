//============================================================================
// Problem  : ABC 44 A - Tak and Hotels (ABC Edit)
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,k,x,y;
    while(cin >> n >> k >> x >> y) {
        cout << (n <= k? n*x : k*x + (n-k)*y) << '\n'; 
    }
    return 0;
}