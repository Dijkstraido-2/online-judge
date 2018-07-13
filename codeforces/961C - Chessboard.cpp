//============================================================================
// Problem  : 961C - Chessboard
// Category : Brute Force
//============================================================================
#include <bits/stdc++.h>
using namespace std;

char M[4][105][105];
char R[305][305];
int n,v[4],ans,cont;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n)
    {
        for(int k = 0; k < 4; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    cin >> M[k][i][j];
        for(int i = 0; i < 4; i++)
            v[i] = i;
        ans = 100000;
        do
        {
            for(int k = 0; k < 4; k++)
            {
                int offR = (k < 2? 0 : n);
                int offC = (k == 0 || k == 2? 0 : n);
                for(int i = 0; i < n; i++)
                    for(int j = 0; j < n; j++)
                        R[offR + i][offC + j] = M[v[k]][i][j]; 
            }
            cont = 0;
            for(int i = 0; i < 2*n; i++)
                for(int j = 0, color = (i % 2 == 0); j < 2*n; j++, color = !color)
                    if(R[i][j] != color+'0')
                        cont++;
            ans = min(ans, cont);
            cont = 0;
            for(int i = 0; i < 2*n; i++)
                for(int j = 0, color = (i % 2 != 0); j < 2*n; j++, color = !color)
                    if(R[i][j] != color+'0')
                        cont++;
            ans = min(ans, cont);
        }while(next_permutation(v, v+4));
        cout << ans << '\n';
    }
    return 0;
}