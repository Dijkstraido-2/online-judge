//============================================================================
// Problem  : 79A - Milk and Bread
// Category : Basic Programming
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int x,y,z;
    while(cin >> x >> y >> z)
        cout << min(abs(z-y) + abs(y-x), abs(z-x) + abs(x-y)) << '\n';
    return 0;
}