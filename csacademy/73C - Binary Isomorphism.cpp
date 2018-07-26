//============================================================================
// Judge    : 73C - Binary Isomorphism
// Category : Tree Isomorphism (rooted tree)
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi g[2];
int n;

ll hsh(int i, int v, int p = -1)
{
    ll ans = 350913135101LL;
    for(int u : g[i][v])
        if(p != u)
            ans += hsh(i, u, v);
    return ans ^ 23585918359LL;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T,p;
    cin >> T;
    while(T--)
    {
        cin >> n; n++;
        for(int k = 0; k < 2; k++)
        {
            g[k] = vvi(n);
            for(int i = 1; i < n; i++)
            {
                cin >> p;
                g[k][p].push_back(i);
            }
        }
        cout << (hsh(0,0) == hsh(1,0)) << '\n';
    }
    return 0;
}