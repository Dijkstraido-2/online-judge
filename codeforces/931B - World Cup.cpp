//============================================================================
// Judge    : 931B - World Cup
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,a,b,cont;
    while(cin >> n >> a >> b)
    {
        cont = 0; a += n-1; b += n-1;
        while(a != b)
        {
            a /= 2; b /= 2;
            cont++;
        }
        if((1 << cont) == n)
            cout << "Final!" << '\n';
        else
            cout << cont << '\n';
    }
    return 0;
}