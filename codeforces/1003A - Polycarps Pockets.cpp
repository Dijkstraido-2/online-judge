//============================================================================
// Problem  : 1003A - Polycarps Pockets
// Category : Basic Programming
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int f[105],n,x;
    while(cin >> n)
    {
        memset(f, 0, sizeof f);
        for(int i = 0; i < n; i++) { cin >> x; f[x]++; }
        cout << *max_element(f, f+105) << '\n';
    }
    return 0;
}