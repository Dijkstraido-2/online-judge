//============================================================================
// Problem  : 1017A - The Rank
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,t,s,a,b,c,d,cont=0;
    while(cin >> n)
    {
        cin >> a >> b >> c >> d;
        t = a+b+c+d; cont = 0;
        for(int i = 1; i < n; i++)
        {
            cin >> a >> b >> c >> d;
            s = a+b+c+d;
            if(s > t)
                cont++;
        }
        cout << 1+cont << '\n';
    }
    return 0;
}