//============================================================================
// Problem  : 965B - Battleship
// Category : Brute force
//============================================================================
#include <bits/stdc++.h>
using namespace std;

string M[105];
int dp[105][105];
int cont[105][105];

int sum(int px, int py, int ex, int ey) 
{
    return dp[ex+1][ey+1] - dp[ex+1][py] - dp[px][ey+1] + dp[px][py];
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,k,px,py;
    while(cin >> n >> k)
    {
        memset(dp, 0, sizeof dp);
        for(int i = 0; i < n; i++)
        {
            cin >> M[i];
            for(int j = 0; j < n; j++)
                dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j] - dp[i][j] + (M[i][j] == '.');
        }

        memset(cont, 0, sizeof cont);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                for(int l = j-k+1; l <= j; l++)
                    if(l >= 0 && l+k-1 < n && sum(i,l,i,l+k-1) == k)
                        cont[i][j]++;

                for(int l = i-k+1; l <= i; l++)
                    if(l >= 0 && l+k-1 < n && sum(l,j,l+k-1,j) == k)
                        cont[i][j]++;
            }

        int maxi = -1;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(cont[i][j] > maxi)
                {
                    maxi = cont[i][j];
                    px = i+1; py = j+1;
                }
        cout << px << " " << py << '\n';
    }
    return 0;
}