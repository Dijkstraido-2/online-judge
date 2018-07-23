//============================================================================
// Problem  : 77A - Quadrants
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,x,y,f[4];
    while(cin >> n)
    {
        memset(f, 0, sizeof f);
        for(int i = 0; i < n; i++)
        {
            cin >> x >> y;
            if(x > 0 && y > 0)
                f[0]++;
            else if(x > 0 && y < 0)
                f[1]++;
            else if(x < 0 && y > 0)
                f[2]++;
            else
                f[3]++;
        }
        int ans = 0;
        for(int i = 0; i < 4; i++)
            if(f[i])
                ans++;
        cout << ans << '\n';
    }
    return 0;
}