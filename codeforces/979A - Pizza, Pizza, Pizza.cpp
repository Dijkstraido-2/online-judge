//============================================================================
// Problem  : 979A - Pizza, Pizza, Pizza
// Category : Simple Math
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    while(cin >> n)
    {
        if(n == 0)
            cout << 0 << '\n';
        else
        {
            n++;
            cout << (n % 2 == 0? n/2 : n) << '\n';
        }
    }
    return 0;
}