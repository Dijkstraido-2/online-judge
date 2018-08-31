//============================================================================
// Problem  : 933B - A Determined Cleanup
// Category : Math
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

vi toNegativeBase(ll x, ll b) 
{
    if(!x) { return {0}; }
    vi ans;
    while(x != 0) 
    {
        ll r = x%b;
        x /= b;
        if(r < 0) { r += -b; x++; }
        ans.push_back(r);
    }
    return ans;
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll p,k;
    while(cin >> p >> k)
    {
        vi ans = toNegativeBase(p, -k);
        cout << ans.size() << '\n';
        for(auto it : ans)
            cout << it << " ";
        cout << '\n';
    }
    return 0;
}