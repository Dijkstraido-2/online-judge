//============================================================================
// Problem  : 1003C - Intense Heat
// Category : Brute force
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,k;
    vi v;
    while(cin >> n >> k)
    {
        v = vi(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        double ans = 0.0;
        for(int i = 0; i < n; i++)
        {
            int sum = 0;
            for(int j = i; j < n; j++)
            {
                sum += v[j];
                if(j-i+1 >= k)
                    ans = max(ans, 1.*sum/(j-i+1));
            }
        }
        cout << fixed << setprecision(8) << ans << '\n';
    }
    return 0;
}