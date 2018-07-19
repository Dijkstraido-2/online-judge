//============================================================================
// Problem  : 84C - Split the Sticks
// Category : Greedy
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    ll x, s = 0;
    multiset<ll> ms;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        ms.insert(x);
        s += x;
    }
    if(s % 2 != 0)
        cout << -1 << '\n';
    else
    {
        vii ans;
        while(!ms.empty()) 
            if(ms.size() == 1) 
            {
                x = *ms.begin(); ms.clear();
                ans.push_back({x, x/2});
            }
            else 
            {
                ll mn = *ms.begin(); ms.erase(ms.find(mn));
                ll mx = *(--ms.end()); ms.erase(ms.find(mx));
                if(mn < mx) 
                {
                   ans.push_back({mx, mx - mn});
                   ms.insert(mx -mn);
                }
            }
        cout << ans.size() << '\n';
        for(auto it : ans)
            cout << it.first << " " << it.second << '\n';
    }
    return 0;
}