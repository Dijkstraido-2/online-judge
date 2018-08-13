//============================================================================
// Judge    : 919A - Supermarket
// Category : Basic Programming
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,a,b,x,y;
    while(cin >> n >> m)
    {
        cin >> a >> b;
        for(int i = 1; i < n; i++)
        {
            cin >> x >> y;
            if(x * b < a * y)
                a = x, b = y;
        }
        cout << fixed << setprecision(8) << m * a * 1.0 / b << '\n';
    }
    return 0;
} 