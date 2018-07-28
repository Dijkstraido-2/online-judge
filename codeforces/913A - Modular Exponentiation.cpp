//============================================================================
// Problem  : 913A - Modular Exponentiation
// Category : Basic Programming
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;  

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n,m,mod;
    while(cin >> n >> m)
    {
        if(n < 32)
        {
            mod = (1LL << n);
            cout << m % mod << '\n';
        }
        else
            cout << m << '\n';
    }
    return 0;
} 