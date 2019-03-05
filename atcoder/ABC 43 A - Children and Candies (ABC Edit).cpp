//============================================================================
// Problem  : ABC 43 A - Children and Candies
// Category : Simple Math 
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin >> n) {
        cout << n*(n+1)/2 << '\n';
    }
    return 0;
}