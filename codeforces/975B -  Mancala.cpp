//============================================================================
// Problem  : 975B -  Mancala
// Category : Brute force
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll v[15],a[15],ans = 0;
    for(int i = 0; i < 14; i++)
        cin >> v[i];
    for(int k = 0; k < 14; k++)
        if(v[k] > 0)
        {
            for(int i = 0; i < 14; i++)
                a[i] = v[i];
            ll m = a[k] % 14;
            ll e = ceil(a[k] / 14.);
            a[k] = 0;
            int used[14];
            memset(used, 0, sizeof used);
            for(int i = 1; i <= m; i++)
            {
                a[(k+i) % 14] += e;
                used[(k+i) % 14] = 1;
            }
            for(int i = 0; i < 14; i++)
                if(!used[i])
                    a[i] += e-1;

            ll cant = 0;
            for(int i = 0; i < 14; i++)
                if(a[i] % 2 == 0)
                    cant += a[i];
            ans = max(ans, cant);
        }
    cout << ans << '\n';
    return 0;
}