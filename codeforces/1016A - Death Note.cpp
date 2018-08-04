//============================================================================
// Problem  : 1016A - Death Note
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n,m,cur,x;
    while(cin >> n >> m)
    {
        cur = 0;
        for(int i = 0; i < n; i++) 
        {
            cin >> x;
            cur += x; 
            cout << " " << cur/m;
            cur %= m;
        }
        cout << '\n';
    }
    return 0; 
}