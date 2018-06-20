//============================================================================
// Problem  : 988D - Points and Powers of Two
// Category : Binary Search
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
    ll ans,a[3];
    while(cin >> n)
    {
        v = vi(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        ans = 1; a[0] = v[0];
        for(int i = 0; i < n; i++)
            for(int p = 0; p < 31; p++)
            {
                ll j = v[i] + (1LL << p);
                if(binary_search(v.begin(), v.end(), j))
                {
                    if(ans < 2) { ans = 2; a[0] = v[i]; a[1] = j; }
                    ll k = j + (1LL << p);
                    if(ans < 3 && binary_search(v.begin(), v.end(), k))
                    {
                        ans = 3;
                        a[0] = v[i]; a[1] = j; a[2] = k;
                    }
                }
            }
        cout << ans << '\n';
        for(int i = 0; i < ans; i++)
            cout << a[i] << " \n"[i == ans-1];
    }
    return 0;
}