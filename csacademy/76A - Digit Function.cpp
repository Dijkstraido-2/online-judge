//============================================================================
// Problem  : 76A - Digit Function
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int f(int x)
{
    if(x == 0)
        return 1;
    int s = 0, px = x;
    while(x > 0)
    {
        s += (x % 10); 
        x /= 10;
    }
    return 1 + f(px - s);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin >> n)
        cout << f(n) << '\n';
    return 0;
}