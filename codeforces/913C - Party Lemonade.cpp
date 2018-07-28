//============================================================================
// Problem  : 913C - Party Lemonade
// Category : Greedy
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

const ll INF = 2000000000000000000LL;
vi v;
int n,sum,ans;
ll x;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> x)
    {
        v = vi(32, INF);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        // Update values
        for(int i = 1; i < 32; i++)
            v[i] = min(v[i], v[i-1] * 2);
        // Solve
        ll sum = 0, ans = INF;
        for(int i = 31; i >= 0; i--)
            if(x & (1 << i))
                sum += v[i]; 
            else
                ans = min(ans, sum + v[i]);
        ans = min(ans, sum);
        cout << ans << '\n';
    }
    return 0;
} 