//============================================================================
// Problem  : 978C - Letters
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    ll x,cur,sum;
    vi v;
    while(cin >> n >> m)
    {
        v = vi(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        sum = 0; cur = -1;
        for(int i = 0; i < m; i++)
        {
            cin >> x;
            while(x > sum)
                sum += v[++cur];
            cout << cur+1 << " " << x-(sum-v[cur]) << '\n';
        }
    }
    return 0;
}