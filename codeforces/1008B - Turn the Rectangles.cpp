//============================================================================
// Problem  : 1008B - Turn the Rectangles
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,a,b,x,y,p,q,np,nq;
    while(cin >> n)
    {
        cin >> a >> b; p = q = 1;
        for(int i = 1; i < n; i++)
        {
            cin >> x >> y;
            np = (p && x <= a) || (q && x <= b);
            nq = (p && y <= a) || (q && y <= b);
            p = np; q = nq; a = x; b = y;
        }
        cout << (p || q? "YES" : "NO") << '\n';
    }
    return 0;
}