//============================================================================
// Judge    : 73B - Ricocheting Balls
// Category : Sorting
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

vi v;
int n;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n)
    {
        v = vi(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        ll ans = 0, n = v.size();
        for(int x : v)
            ans += labs(x - v[n/2]);
        cout << ans << '\n';
    }
    return 0;
}