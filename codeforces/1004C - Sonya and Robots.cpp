//============================================================================
// Problem  : 1004C - Sonya and Robots
// Category : Map
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    vi v;
    while(cin >> n)
    {
        v = vi(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        map<ll,ll> a,b;
        for(int i = 1; i < n; i++)
            b[v[i]]++;
        // count
        ll ans = 0;
        for(int i = 0; i < n-1; i++)
        {
            if(i)
            {
                b[v[i]]--;
                if(b[v[i]] == 0)
                    b.erase(v[i]);
            }
            if(a[v[i]] == 0)
            {
                ans += b.size();
                a[v[i]]++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}