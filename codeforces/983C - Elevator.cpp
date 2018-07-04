//============================================================================
// Problem  : 983C - Elevator
// Category : DP
//============================================================================
#include <bits/stdc++.h>
using namespace std;

const int INF = 20000000;
int n,a[2005],b[2005];
int dp[2005][9][10][10][10]; // (pos, floor, dest#1, dest#2, dest#3)

int solve(int i, int f, int x, int y, int z) 
{
    if(i == n && x == 9 && y == 9 && z == 9) return 0;
    if(dp[i][f][x][y][z] != -1) return dp[i][f][x][y][z];
    int ans = INF;
    if(x != 9) ans = min(ans, solve(i,x,9,y,z) + abs(f-x));
    if(y != 9) ans = min(ans, solve(i,y,x,9,z) + abs(f-y));
    if(z != 9) ans = min(ans, solve(i,z,x,y,9) + abs(f-z));
    if(i < n)
    {
        if(x == 9)      ans = min(ans, solve(i+1,a[i],b[i],y,z) + abs(f-a[i]));
        else if(y == 9) ans = min(ans, solve(i+1,a[i],x,b[i],z) + abs(f-a[i]));
        else if(z == 9) ans = min(ans, solve(i+1,a[i],x,y,b[i]) + abs(f-a[i]));
        else
        {   // Pick the last one and leave any of the 4 currently inside
            ans = min(ans, solve(i+1,b[i],x,y,z) + abs(f-a[i]) + abs(a[i]-b[i]));
            ans = min(ans, solve(i+1,x,b[i],y,z) + abs(f-a[i]) + abs(a[i]-x));
            ans = min(ans, solve(i+1,y,x,b[i],z) + abs(f-a[i]) + abs(a[i]-y));
            ans = min(ans, solve(i+1,z,x,y,b[i]) + abs(f-a[i]) + abs(a[i]-z));
        }
    }
    return dp[i][f][x][y][z] = ans;
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n)
    {
        for(int i = 0; i < n; a[i]--,b[i]--,i++)
            cin >> a[i] >> b[i];
        memset(dp, -1, sizeof dp);
        cout << solve(0,0,9,9,9) + 2*n << '\n';
    }
    return 0;
}