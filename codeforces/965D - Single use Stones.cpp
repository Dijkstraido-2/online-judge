//============================================================================
// Problem  : 965D - Single-use Stones
// Category : Greedy
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,k,s,l,r,v[100005],ans;
    while(cin >> n >> k)
    {
        l = s = 0; ans = 1e9+5;
        for(int i = 0; i < n-1; i++)
        {
            cin >> v[i];
            s += v[i]; r = i;
            while(r-l+1 > k)
            {
                s -= v[l];
                l++;
            }
            if(r-l+1 == k)
                ans = min(ans, s);
        }
        cout << ans << '\n';
    }
    return 0;
}