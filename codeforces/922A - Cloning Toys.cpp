//============================================================================
// Judge    : 922A - Cloning Toys
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll x,y,d;
    while(cin >> x >> y)
    {
        if(y == 0)
            cout << "No" << '\n';
        else if(y == 1)
            cout << (x == 0? "Yes" : "No") << '\n';
        else
            cout << (y - x == 1 || (x > y && (x - y) % 2 != 0)? "Yes" : "No") << '\n';
    }
    return 0;
}