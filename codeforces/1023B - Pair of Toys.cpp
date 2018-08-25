//============================================================================
// Problem  : 1023B - Pair of Toys
// Category : Simple Math
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n,m,k;
    while(cin >> n >> k)
    {
        if(n >= k-1)
            cout << (k-1)/2 << '\n';
        else 
        {
            m = k-n;
            cout << (m <= n? (n-m+1)/2 : 0) << '\n';
        }
    } 
    return 0;
}