//============================================================================
// Problem  : 990A - Commentary Boxes
// Category : Basic Math
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n,m,a,b,f;
    while(cin >> n >> m >> a >> b)
    {
        f = n/m;
        cout << min((n-m*f)*b, (m*(f+1)-n)*a) << '\n';
    }
    return 0;
}