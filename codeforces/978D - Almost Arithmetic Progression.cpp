//============================================================================
// Problem  : 978D - Almost Arithmetic Progression
// Category : Brute force
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
const int INF = 20000000;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    vi v,cop;
    while(cin >> n)
    {
        v = vi(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        cop = v;
        if(n <= 2) { cout << 0 << '\n'; continue; }
        int ans = INF;
        for(int a = -1; a <= 1; a++)
            for(int b = -1; b <= 1; b++)
            {
                v[0] += a; v[1] += b;
                ll r = v[1] - v[0];
                int cont = abs(a) + abs(b);
                int posible = 1;
                for(int i = 2; i < n && posible; i++)
                {
                    int ok = 0;
                    for(int c = -1; c <= 1; c++)
                        if(v[i]+c - v[i-1] == r)
                        {
                            ok = 1;
                            v[i] += c;
                            cont += abs(c);
                            break;
                        }
                    if(!ok)
                        posible = 0;
                }
                if(posible)
                    ans = min(ans, cont);
                v = cop;
            }
        cout << (ans == INF? -1 : ans) << '\n';
    }
    return 0;
}