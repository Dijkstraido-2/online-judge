//============================================================================
// Problem  : 1027C - Minimum Value Rectangle
// Category : Greedy
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll T,n,x,y,a,b;
    vi v;
    map<ll,int> mp;
    cin >> T;
    while(T--)
    {
        cin >> n; mp.clear();
        for(int i = 0; i < n; i++)
        {
            ll x; cin >> x;
            mp[x]++;
        }
        v.clear();
        for(auto it : mp) 
        {
            if(it.second >= 2) v.push_back(it.first);
            if(it.second >= 4) v.push_back(it.first);
        }
        n = v.size(); x = y = -1; 
        for(int i = 0; i+1 < n; i++)
        {
            ll num = (2*v[i] + 2*v[i+1])*(2*v[i] + 2*v[i+1]);
            ll den = (v[i]*v[i+1]);
            if(x == -1 || (num * y < den * x)) 
            {
                x = num, y = den;
                a = v[i], b = v[i+1];
            }
        }
        cout << a << " " << a << " " << b << " " << b << '\n';
    }
    return 0;
}