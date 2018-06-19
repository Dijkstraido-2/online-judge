//============================================================================
// Problem  : 992B - Nastya Studies Informatics
// Category : Number Theory
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll l,r,x,y;

int valid(ll n) { return l <= n && n <= r; }

int main()
{
    while(cin >> l >> r >> x >> y)
    {
        if(y % x != 0) { cout << 0 << '\n'; continue; }
        ll d = y/x, ans = 0;
        for(ll a = 1; a*a <= d; a++)
            if(d % a == 0)
            {
                ll b = d/a;
                if(valid(a*x) && valid(b*x) && __gcd(a,b) == 1)
                    ans += (a==b? 1 : 2);
            }
        cout << ans << '\n';
    }
    return 0;
}