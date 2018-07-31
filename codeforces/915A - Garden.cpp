//============================================================================
// Problem  : 915A - Garden
// Category : Basic Programming
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,k,x,ans;
    while(cin >> n >> k)
    {
        ans = 10000000;
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            if(k % x == 0)
                ans = min(ans, k / x);
        }
        cout << ans << '\n';
    }
    return 0;
}