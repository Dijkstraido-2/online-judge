//============================================================================
// Problem  : 79B - Cats and Dogs
// Category : Brute force
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vii c,d;
vi cont;
int n,m;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> m)
    {
        c = vii(n); cont = vi(n, 0);
        for(int i = 0; i < n; i++)
            cin >> c[i].first >> c[i].second;
        d = vii(m); 
        for(int i = 0; i < m; i++)
        {
            cin >> d[i].first >> d[i].second;
            int bst = 200000000, idx = -1;
            for(int j = 0; j < n; j++)
            {
                int dis = (c[j].first - d[i].first) * (c[j].first - d[i].first) + 
                           (c[j].second - d[i].second) * (c[j].second - d[i].second);
                if(dis < bst)
                {
                    bst = dis;
                    idx = j;
                }
            }
            cont[idx]++;
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
            if(cont[i] == 1)
                ans++;
        cout << ans << '\n';
    }
    return 0;
}