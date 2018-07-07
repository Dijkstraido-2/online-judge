//============================================================================
// Problem  : 997A - Convert to Ones
// Category : Brute force
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n,x,y;
    string s;
    while(cin >> n >> x >> y >> s)
    {
        ll start = 0, blocks = 0;
        for(int i = 0; i < n; i++)
            if(s[i] == '0')
                start = 1;
            else if(s[i] == '1' && start)
            {
                blocks++;
                start = 0;
            }
        if(start)
            blocks++;

        ll ans = blocks * y;
        for(int i = 0; i < blocks; i++)
            ans = min(ans, i * x + (blocks-i) * y);
        cout << ans << '\n';
    }
    return 0;
}