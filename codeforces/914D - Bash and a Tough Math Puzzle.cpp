//============================================================================
// Problem  : 914D - Bash and a Tough Math Puzzle
// Category : Segment Tree
//============================================================================
#include <bits/stdc++.h>
using namespace std;

const int MAX = 500005;
int t[2*MAX];
int n;

void build()
{
    for(int i = n - 1; i > 0; i--)
        t[i] = __gcd(t[i << 1], t[i << 1 | 1]);
}

void upd(int i, int x)
{
    for(t[i += n] = x; i >>= 1;)
        t[i] = __gcd(t[i << 1], t[i << 1 | 1]);
}

bool split(int pos, int val)
{
    if(pos >= n) return true;
    int l = pos << 1;
    int r = pos << 1 | 1;
    int cant = 0, nxt;
    if(t[l] % val != 0)
    {
        cant++;
        nxt = l;
    }
    if(t[r] % val != 0)
    {
        cant++;
        nxt = r;
    }
    return cant == 2? false : split(nxt, val);
}

bool query(int l, int r, int val)
{
    int ans = 0, cont = 0, pos;
    for(l += n, r += n; l <= r; l = (l+1) >> 1, r = (r-1) >> 1)
    {
        if(  l & 1 ) 
        {
            ans = __gcd(ans, t[l]);
            if(t[l] % val != 0)
            {
                cont++;
                pos = l;
            }
        }
        if(!(r & 1)) 
        {
            ans = __gcd(t[r], ans);
            if(t[r] % val != 0)
            {
                cont++;
                pos = r;
            }
        }
    }
    if(ans == val)
        return true;
    else if(cont >= 2)
        return false;
    else
        return split(pos, val); 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int q,opc,x,y,val;
    while(cin >> n)
    {
        for(int i = 0; i < n; i++)
            cin >> t[i+n];
        build();
        cin >> q;
        while(q--)
        {
            cin >> opc >> x >> y;
            if(opc == 1)
            {  
                cin >> val; 
                cout << (query(--x, --y, val)? "YES" : "NO") << '\n';
            }
            else
                upd(--x, y);
        }
    }
    return 0;
}