//============================================================================
// Problem  : 984B - Minesweeper
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int aux_x[8] = {-1,-1,-1,0,1,1, 1, 0};
int aux_y[8] = {-1, 0, 1,1,1,0,-1,-1};

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int r,c;
    string M[105];
    while(cin >> r >> c)
    {
        for(int i = 0; i < r; i++)
            cin >> M[i];
        
        int ok = 1;
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                if(M[i][j] != '*')
                {
                    int cant = (M[i][j]  == '.')? 0 : (M[i][j] - '0');
                    int cont = 0;
                    for(int k = 0; k < 8; k++)
                    {
                        int nx = i + aux_x[k];
                        int ny = j + aux_y[k];
                        if(nx > -1 && ny > -1 && nx < r && ny < c && M[nx][ny] == '*')
                            cont++;
                    }
                    if(cant != cont)
                        ok = 0;
                }
        cout << (ok? "YES" : "NO") << '\n';
    }
    return 0;
}