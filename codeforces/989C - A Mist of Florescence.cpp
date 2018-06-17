//============================================================================
// Problem  : 989C - A Mist of Florescence
// Category : Constructive algorithm
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int f[4],r=48,c=50;
    char M[55][55];
    while(cin >> f[0] >> f[1] >> f[2] >> f[3])
    {
        for(int i = 0; i < 4; i++)
            for(int x = 12*i; x < 12*(i+1); x++)
                for(int y = 0; y < c; y++)
                    M[x][y] = 'A'+i;

        for(int i = 0; i < 4; i++)
        {
            int px = 12*i + 1, py = 1, cur = (i+1)%4;
            for(int j = 0; j < f[cur] - 1; j++)
            {
                M[px][py] = cur + 'A';
                py += 2;
                if(py >= c) { px += 2; py = 1; }
            }
        }

        cout << r << " " << c << '\n';
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
                cout << M[i][j];
            cout << "\n";
        }
    }
    return 0;
}
