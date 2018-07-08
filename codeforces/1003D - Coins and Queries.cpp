//============================================================================
// Problem  : 1003D - Coins and Queries
// Category : Greedy
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,q,x;
    while(cin >> n >> q)
    {
        vector<int> fr(32, 0);
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            fr[__builtin_ctz(x)]++;
        }
        while(q--)
        {
            cin >> x;
            vector<int> f = fr;
            int ans = 0, ok = 1;
            for(int i = 31; i >= 0; i--)
                if(x & (1 << i))
                {
                    int need = 1;
                    for(int j = i; j >= 0; j--)
                    {
                        int taken = min(need, f[j]);
                        f[j] -= taken;
                        ans += taken;
                        need = (need-taken)*2;
                    }
                    if(need)
                        ok = 0;
                }
            cout << (!ok? -1 : ans) << '\n';
        } 
    }
    return 0;
}