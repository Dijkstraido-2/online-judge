//============================================================================
// Judge    : 73D - Russian Dolls Ways
// Category : Sorting + Greedy + Math
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

const ll MOD = 1e9+7;
vi v;
map<ll,int> mp;
int n;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll x,maxi,ans;
    while(cin >> n)
    {
        mp.clear();
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            mp[x]++;
        }
        v.clear();
        for(auto p : mp)
            v.push_back(p.second);
        sort(v.begin(), v.end()); 
        maxi = v.back(); v.pop_back();
        ans = 1;
        for(ll x : v)
            for(int i = 0; i < x; i++)
                ans = (ans * (maxi-i)) % MOD;
        cout << ans << '\n';
    }
    return 0;
}