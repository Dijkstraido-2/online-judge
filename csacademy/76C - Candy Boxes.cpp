//============================================================================
// Problem  : 76C - Candy Boxes
// Category : Greedy
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vi v,ans;
vii q;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    while(cin >> n >> m)
    {
        v = vi(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        q = vii(m); ans = vi();
        int cont = 0;
        for(int i = 0; i < m; i++)
        {
            cin >> q[i].first;
            if(q[i].first == 1)
            {
                cin >> q[i].second; q[i].second--;
                v[q[i].second]--;
                if(v[q[i].second] < 0)
                    ans.push_back(q[i].second);
            }
            else
                cont++;
        }
        for(int x : ans)
            cout << x+1 << '\n';
        for(int i = 0; i < cont - (int)ans.size(); i++)
            cout << 1 << '\n';
    }
    return 0;
}