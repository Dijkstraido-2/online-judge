//============================================================================
// Problem  : 79D - Groups
// Category : Brute force
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
int n,k,q;
vi id;
vvi v;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int sz,x;
    while(cin >> n >> k >> q)
    {
        id = vi(n+1, -1);
        v = vvi(k);
        for(int i = 0; i < k; i++)
        {
            cin >> sz; v[i] = vi(sz);
            for(int j = 0; j < sz; j++)
                cin >> v[i][j];
            id[v[i][0]] = i;
        }
        while(q--)
        {
            cin >> sz;
            vector<int> cand;
            unordered_set<int> cur;
            for(int i = 0; i < sz; i++)
            {
                cin >> x;
                cur.insert(x);
                if(id[x] != -1)
                    cand.push_back(id[x]);
            }
            int ans = 0;
            for(int g : cand)
            {
                int ok = 1;
                for(int aux : v[g])
                    if(cur.find(aux) == cur.end())
                    {
                        ok = 0;
                        break;
                    }
                if(ok) ans++;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}