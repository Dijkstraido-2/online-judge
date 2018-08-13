//============================================================================
// Judge    : 919C - Seat arrangements
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

string M[2005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int r,c,k,ans;
    while(cin >> r >> c >> k)
    {
        for(int i = 0; i < r; i++)
            cin >> M[i];

        ans = 0;
        for(int i = 0; i < r; i++)
            for(int j = 0, cont = 0; j < c; j++)
                if(M[i][j] == '.')
                {
                    cont++;
                    ans += (cont >= k);
                }
                else
                    cont = 0;
        if(k >= 2)
        {
            for(int j = 0; j < c; j++)
                for(int i = 0, cont = 0; i < r; i++)
                    if(M[i][j] == '.')
                    {
                        cont++;
                        ans += (cont >= k);
                    }
                    else
                        cont = 0;
        }
        cout << ans << '\n';
    }
    return 0;
} 