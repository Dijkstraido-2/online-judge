//============================================================================
// Problem  : 1061A - Coins
// Category : Simple Math
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,s;
    while(cin >> n >> s) 
        cout << (int)ceil(s*1./n) << '\n';    
    return 0;
}