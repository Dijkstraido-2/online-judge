//============================================================================
// Judge    : 920A - Water the Garden
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T,n,k,ans;
    vi v;
    cin >> T;
    while(T--)
    {
        cin >> n >> k;
        v = vi(k);
        for(int i = 0; i < k; i++)
            cin >> v[i];
        ans = v[0];
        for(int i = 1; i < k; i++)
            ans = max(ans, (v[i]-v[i-1])/2 + 1);
        ans = max(ans, n - v[k-1] + 1);
        cout << ans << '\n';
    }
    return 0;
}