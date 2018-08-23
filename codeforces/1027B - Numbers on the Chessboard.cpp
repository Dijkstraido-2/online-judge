//============================================================================
// Problem  : 1027B - Numbers on the Chessboard
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n,q,x,y;
    while(cin >> n >> q)
    {
        while(q--)
        {
            cin >> x >> y; x--; y--;
            if(n % 2 == 0) 
                cout << ((x+y)%2? n*n/2 : 0) + x*(n/2) + (y/2 + 1) << '\n';
            else if((x+y) % 2) 
                cout << (n*n/2+1) + (x/2)*(n/2 + (n+1)/2) + (x%2? n/2 : 0) + (y/2 + 1) << '\n';
            else
                cout << (x/2)*(n/2 + (n+1)/2) + (x%2? (n+1)/2 : 0) + (y/2 + 1) << '\n';
        }
    }
    return 0;
}