//============================================================================
// Problem  : 978E - Bus Video System
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    ll w,x,l,r,s;
    while(cin >> n >> w)
    {
        l = 0; r = w; s = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            s += x;
            l = max(l, -s);
            r = min(r, w-s);
        }
        cout << max(0LL, r-l+1) << '\n';
    }
    return 0;
}