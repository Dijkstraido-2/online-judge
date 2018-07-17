//============================================================================
// Problem  : 1006F - Xor Paths
// Category : Meet in the middle
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ans,r,c,k,M[25][25];
map<ll,ll> mp[25][25];
int aux_x[4] = {0,1,0,-1};
int aux_y[4] = {1,0,-1,0};

void backtrack(ll x, ll y, ll cur, int dir) 
{
    if(x+y == (r+c)/2-1) 
    {
        if(dir == 0)
            mp[x][y][cur]++;
        else
            ans += mp[x][y][k^cur^M[x][y]];
        return;
    }
    for(int i = 0; i < 2; i++)
    {
        int nx = x + aux_x[i+dir*2];
        int ny = y + aux_y[i+dir*2];
        if(nx >= 0 && ny >= 0 && nx < r && ny < c)
            backtrack(nx, ny, cur^M[x][y], dir);
    }
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> r >> c >> k)
    {
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++) {
                cin >> M[i][j];
                mp[i][j].clear();
            }
        ans = 0;
        backtrack(0,0,0,0);
        backtrack(r-1,c-1,0,1);
        cout << ans << '\n';
    }
    return 0;
}