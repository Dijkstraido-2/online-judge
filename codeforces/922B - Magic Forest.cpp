//============================================================================
// Judge    : 922B - Magic Forest
// Category : Brute force
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,ans;
    while(cin >> n)
    {
        ans = 0;
        for(int a = 1; a <= n; a++)
            for(int b = a; b <= n; b++)
            {
                int c = a ^ b;
                if(c >= b && c <= n && c < a + b && b < a + c && a < b + c)
                    ans++;
            }
        cout << ans << '\n';
    }
    return 0;
}