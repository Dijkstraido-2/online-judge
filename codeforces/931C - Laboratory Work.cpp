//============================================================================
// Judge    : 931C - Laboratory Work
// Category : Greedy (Sorting)
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vi v,p,q;
int n;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int l,r,mini;
    while(cin >> n)
    {
        v = vi(n); 
        for(int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        if(abs(v[n-1] - v[0]) <= 1)
        {
            cout << n << '\n';
            for(int x : v)
                cout << x << " ";
            cout << '\n';
        }
        else
        {
            l = r = -1; mini = v[0];
            for(int i = 0; i < n; i++)
                if(v[i] == v[0]+1)
                {
                    if(l == -1)
                        l = i;
                    r = i;
                }
            if(l == -1)
            {
                int pos = -1;
                for(int i = 0; i < n - 1 && pos == -1; i++)
                    if(v[i] + 2 == v[i+1])
                        pos = i;
                int cont = 0;
                for(int a = pos, b = pos + 1; a >= 0 && b < n; a--, b++)
                {
                    v[a] = v[b] = mini+1;
                    cont += 2;
                }
                cout << n - cont << '\n';
                for(int x : v)
                    cout << x << " ";
                cout << '\n';
            }
            else
            {
                int cont1 = 0; p = v;
                for(int a = l, b = r; a < b; a++, b--)
                {
                    p[a] = mini; p[b] = mini+2;
                    cont1 += 2;
                }
                int cont2 = 0; q = v;
                for(int a = l-1, b = r+1; a >= 0 && b < n; a--, b++)
                {
                    q[a] = q[b] = mini+1;
                    cont2 += 2;
                }
                if(cont2 >= cont1)
                {
                    swap(cont2, cont1);
                    swap(p, q);
                }
                cout << n - cont1 << '\n';
                for(int x : p)
                    cout << x << " ";
                cout << '\n';
            }
        }
    }
    return 0;
}