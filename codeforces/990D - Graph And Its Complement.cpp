//============================================================================
// Problem  : 990D - Graph And Its Complement
// Category : Constructive algorithms
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int n,a,b,M[1005][1005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> a >> b)
    {
        if(n == 1)
            cout << "YES" << '\n' << 0 << '\n';
        else if(min(a,b) > 1)
            cout << "NO" << '\n';
        else if(n <= 3 && a == 1 && b == 1)
            cout << "NO" << '\n';
        else
        {
            memset(M, 0, sizeof M);
            if(a == 1 && b == 1) // 1 big chain
            {
                for(int i = 0; i < n-1; i++)
                    M[i][i+1] = M[i+1][i] = 1;
            }
            else
            {
                for(int i = max(a,b); i < n; i++)
                    M[0][i] = M[i][0] = 1;
                if(a == 1) // flip
                {
                    for(int i = 0; i < n; i++)
                        for(int j = 0; j < n; j++)
                            if(i != j)
                                M[i][j] = 1-M[i][j];
                }
            }
            // Print
            cout << "YES" << '\n';
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                    cout << M[i][j];
                cout << '\n';
            }
        }
    }
    return 0;
}