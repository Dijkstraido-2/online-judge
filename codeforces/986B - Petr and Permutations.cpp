//============================================================================
// Problem  : 986B - Petr and Permutations
// Category : Math
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vi p,color;
int n;

void visit(int v)
{
    color[v] = 1;
    if(!color[p[v]])
        visit(p[v]);
}

int isOdd()
{
    int c = 0;
    color = vi(n, 0);
    for(int i = 0; i < n; i++)
        if(!color[p[i]])
        {
            visit(p[i]);
            c ^= 1;
        }
    return c;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n) 
    {
        p = vi(n);
        for(int i = 0; i < n; i++)
            cin >> p[i], p[i]--;
        cout << (n < 1000? "Petr" : isOdd()? "Um_nik" : "Petr") << '\n';
    }
    return 0;
}