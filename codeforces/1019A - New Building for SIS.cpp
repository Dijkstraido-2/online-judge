//============================================================================
// Problem  : 1019A - New Building for SIS
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n,h,a,b,q,ta,fa,tb,fb;
    while(cin >> n >> h >> a >> b >> q)
    {
        while(q--)
        {
            cin >> ta >> fa >> tb >> fb;
            ll ans = 0;
            if(ta != tb) {
                if(fa < a)
                    ans += labs(a-fa), fa = a;
                else if(fa > b)
                    ans += labs(b-fa), fa = b;
                if(fb < a) 
                    ans += labs(a-fb), fb = a;
                else if(fb > b) 
                    ans += labs(b-fb), fb = b;
                ans += labs(fa-fb) + labs(ta-tb);
            }
            else  ans += labs(fa-fb);        
            cout << ans << '\n';
        }
    }
    return 0;
}