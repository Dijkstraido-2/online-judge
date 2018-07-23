//============================================================================
// Problem  : 77B - Rhombus
// Category : Greedy
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll p,q,k;
    while(cin >> p >> q >> k)
    {
        for(int i = 0; i < k; i++)
            if(p <= q)
                p++;
            else
                q++;
        cout << fixed << setprecision(7) << p*q/2. << '\n';
    }
    return 0;
}