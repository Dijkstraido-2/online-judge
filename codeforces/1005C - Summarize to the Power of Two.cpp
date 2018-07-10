//============================================================================
// Problem  : 1005C - Summarize to the Power of Two
// Category : Map
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,ans;
    vi v;
    map<ll,int> mp;
    while(cin >> n)
    { 
        mp.clear(); v = vi(n);
        for(int i = 0; i < n; i++) 
        { 
            cin >> v[i]; 
            mp[v[i]]++; 
        }
        ans = 0;
        for(ll x : v) 
        {
            mp[x]--;
            if(mp[x] == 0) 
                mp.erase(x);
            int found = 0;
            for(int i = 0; i < 32; i++)
            {
                ll goal = (1LL << i);
                if(goal > x && mp.find(goal - x) != mp.end())
                    found = 1;
            }
            ans += !found;
            mp[x]++;
        }
        cout << ans << '\n';
    }
    return 0;
}