//============================================================================
// Problem  : 960B - Minimize the error
// Category : Greedy
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
vi a,b,c;
int n;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int k1,k2;
    while(cin >> n >> k1 >> k2)
    {
        a = vi(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        b = vi(n);
        for(int i = 0; i < n; i++)
            cin >> b[i];
        c = vi(n);
        for(int i = 0; i < n; i++)
            c[i] = labs(a[i] - b[i]);
        for(int k = 0; k < k1 + k2; k++)
        {
            ll dif = c[0], pos = 0;
            for(int i = 1; i < n; i++)
                if(c[i] > dif)
                {
                    dif = c[i];
                    pos = i;
                }
            c[pos] = labs(c[pos] - 1);
        }
        ll ans = 0;
        for(int i = 0; i < n; i++)
            ans += c[i]*c[i];
        cout << ans << '\n';
    }
    return 0;
}