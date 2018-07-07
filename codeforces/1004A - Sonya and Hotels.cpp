//============================================================================
// Problem  : 1004A - Sonya and Hotels
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

ll n,d,ans;
vi v;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> d)
    {
        v = vi(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        ans = 2;
        for(int i = 0; i < n-1; i++)
            if(v[i+1] - v[i] == 2*d)
                ans++;
            else if(v[i+1] - v[i] > 2*d)
                ans += 2;
        cout << ans << '\n';
    }
    return 0;
}