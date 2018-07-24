//============================================================================
// Problem  : 76B - Overlapping Matrices
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int r,c,x,y;
    int M[1005][1005],ans[1005][1005];
    cin >> r >> c >> x >> y;
    for(int i = 0; i < r+x; i++)
        for(int j = 0; j < c+y; j++)
            cin >> M[i][j];
                
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            ans[i][j] = M[i][j] - (i >= x && j >= y? ans[i-x][j-y] : 0);
    
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cout << ans[i][j] << " \n"[j==c-1];
    return 0;
}