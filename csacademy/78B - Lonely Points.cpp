//============================================================================
// Problem  : 78B - Lonely Points
// Category : Multiset
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
int n;
vi v;
multiset<ll> ms;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    v = vi(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    for(int i = 1; i < n; i++)
        ms.insert(labs(v[i]-v[i-1]));
    ll ans = 10000000000LL;
    for(int i = 0; i < n; i++)
    {
        // delete point i and put it on max segment
        if(i-1 >= 0)
            ms.erase(ms.find(labs(v[i]-v[i-1])));
        if(i+1 < n)
            ms.erase(ms.find(labs(v[i]-v[i+1])));
        if(i-1 >= 0 && i+1 < n)   
            ms.insert(labs(v[i-1]+v[i+1]));
        ll maxi = *--ms.end(); 
        ms.erase(ms.find(maxi));
        if(maxi % 2 == 0)
        {
            ms.insert(maxi/2);
            ms.insert(maxi/2);
        }
        else 
        {
            ms.insert(maxi/2);
            ms.insert((maxi+1)/2);
        }
        // keep max
        ans = min(ans, *--ms.end());
        // restore
        ms.insert(maxi);
        if(maxi % 2 == 0)
        {
            ms.erase(ms.find(maxi/2));
            ms.erase(ms.find(maxi/2));
        }
        else 
        {
            ms.erase(ms.find(maxi/2));
            ms.erase(ms.find((maxi+1)/2));
        }
        if(i-1 >= 0 && i+1 < n)   
            ms.erase(ms.find(labs(v[i-1]+v[i+1])));
        if(i-1 >= 0)
            ms.insert(labs(v[i]-v[i-1]));
        if(i+1 < n)
            ms.insert(labs(v[i]-v[i+1]));
    }
    cout << ans << '\n';

    return 0;
}