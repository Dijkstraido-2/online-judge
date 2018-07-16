//============================================================================
// Problem  : 1006C - Three Parts of the Array
// Category : 2 Pointer Technique
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    vi v;
    int n;
    while(cin >> n) 
    {
        v = vi(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        int l = -1, r = n;
        ll p = 0, q = 0, ans = 0;
        while(l < r) 
        {
            p += v[++l];
            while(l < r-1 && q < p)
                q += v[--r];
            if(p == q) 
                ans = max(ans, p);
        }
        cout << ans << '\n';
    }
    return 0;
}