//============================================================================
// Problem  : 1037A - Packets
// Category : Bit manipulation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin >> n)
        cout << 32 - __builtin_clz(n) << '\n';
    return 0;
}