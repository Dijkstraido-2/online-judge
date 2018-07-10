//============================================================================
// Problem  : 965A -  Paper Airplanes
// Category : Brute force
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll k,n,s,p;
    while(cin >> k >> n >> s >> p)
    {
        ll ans = -1;
        for(ll packs = 1; packs <= 100000000 && ans == -1; packs++)
        {
            ll sheets = packs * p;
            ll person = sheets / k;
            if(person * s >= n)
                ans = packs; 
        }
        cout << ans << '\n';
    }
    return 0;
}