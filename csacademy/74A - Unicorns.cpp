//============================================================================
// Problem  : 74A - Unicorns
// Category : Brute force
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int A,L,H;
    while(cin >> A >> L >> H)
    {
        for(int r = 0; 2*r <= H; r++)
        {
            int u = H - 2*r;
            int c = A - r - u;
            if(r >= 0 && u >= 0 && c >= 0 && 2*c + 4*r + 4*u == L)
            {
                cout << u << '\n';
                break;
            }
        }
    }
    return 0;
}