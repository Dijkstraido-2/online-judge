//============================================================================
// Problem  : 916A - Jamie and Alarm Snooze
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

bool isOk(int x) { return x % 10 == 7; }

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int x,h,m,cont,ans;
    while(cin >> x >> h >> m)
    {
        cont = ans = 0;
        while(1)
        {
            if(cont == 0 && (isOk(h) || isOk(m)))
                break;
            cont++;
            if(cont == x)
            {
                ans++;
                cont = 0;
            }
            m--;
            if(m < 0)
            {
                m = 59;
                h--;
                if(h < 0)
                    h = 23;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}