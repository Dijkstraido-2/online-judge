//============================================================================
// Problem  : 961A - Tetris
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,p,ans,h[1005];
    while(cin >> n >> m)
    {
        memset(h, 0, sizeof h); ans = 0;
        for(int i = 0; i < m; i++)
        {
            cin >> p; p--;
            h[p]++;
            int ok = 1;
            for(int j = 0; j < n; j++)
                if(!h[j])
                    ok = 0;
            if(ok)
            {
                ans++;
                for(int j = 0; j < n; j++)
                    h[j]--;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}