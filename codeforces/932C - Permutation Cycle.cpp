//============================================================================
// Judge    : 932C - Permutation Cycle
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,a,b,found;
    while(cin >> n >> a >> b)
    {
        found = 0;
        for(int x = 0; a*x <= n && !found; x++)
            if((n - x*a) % b == 0)
            {
                int y = (n - x*a) / b;
                int last = 0;
                for(int i = 0; i < x; i++)
                {
                    cout << " " << a * (i+1);
                    for(int j = last + 1; j < a * (i+1); j++)
                        cout << " " << j;
                    last = a * (i+1);
                }
                int off = last; last = 0; 
                for(int i = 0; i < y; i++)
                {
                    cout << " " << b * (i+1) + off;
                    for(int j = last + 1; j < b * (i+1); j++)
                        cout << " " << j + off;
                    last = b * (i+1);
                }
                found = 1;
            }
        if(!found)
            cout << -1 << '\n';
        else
            cout << '\n';
    }
    return 0;
}