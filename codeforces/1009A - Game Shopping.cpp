//============================================================================
// Problem  : 1009A - Game Shopping
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    int a[1005],b[1005];
    while(cin >> n >> m)
    {
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < m; i++)
            cin >> b[i];

        int p = 0, q = 0, ans = 0;;
        while(p < n && q < m)
        {
            if(b[q] >= a[p]) {
                ans++; q++;
            }
            p++;
        }
        cout << ans << '\n';
    }
    return 0;
}