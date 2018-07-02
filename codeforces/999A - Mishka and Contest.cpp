//============================================================================
// Problem  : 999A - Mishka and Contest
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,k,v[105];
    while(cin >> n >> k)
    {
        for(int i = 0; i < n; i++)
            cin >> v[i];
        int ans = 0;
        for(int i = 0; i < n; i++, ans++)
            if(v[i] > k)
                break;
        for(int i = n-1; i >= 0; i--, ans++)
            if(v[i] > k)
                break;
        cout << min(ans, n) << '\n';
    }
    return 0;
}