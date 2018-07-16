//============================================================================
// Problem  : 959E - Mahmoud and Ehab and the xor-MST
// Category : OEIS
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(ll x) 
{ 
    if(x == 1) 
        return 1;
    else if(x % 2 == 0)
        return 2*f(x/2) + x/2;
    else
        return 2*f(x/2) + x/2 + 1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    while(cin >> n)
        cout << f(n-1) << '\n';
    return 0;
}