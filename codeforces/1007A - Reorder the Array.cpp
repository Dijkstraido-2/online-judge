//============================================================================
// Problem  : 1007A - Reorder the Array
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    map<int,int> mp;
    int n,x;
    while(cin >> n) 
    {
        mp.clear();
        for(int i = 0; i < n; i++) { cin >> x; mp[x]++; }
        int ans = 0;
        if(mp.size() > 1) 
        {
            auto l = mp.begin();
            int tot = 0;
            for(auto r = ++mp.begin(); r != mp.end(); r++) 
            {
                while(l != r && tot < r->second) 
                {
                    tot += l->second;
                    l++;
                }
                ans += min(tot, r->second);
                tot -= min(tot, r->second);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}