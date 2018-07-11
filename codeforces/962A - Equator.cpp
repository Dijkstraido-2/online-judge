//============================================================================
// Problem  : 962A - Equator
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

vi v;
int n;
ll s,cont;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n)
    {
        s = 0; v = vi(n);
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
            s += v[i];
        }
        cont = 0;
        for(int i = 0; i < n; i++)
        {
            cont += v[i];
            if(cont >= (s+1)/2)
            {
                cout << i+1 << '\n';
                break;
            }
        }
    }
    return 0;
}