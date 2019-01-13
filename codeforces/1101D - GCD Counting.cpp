//============================================================================
// Problem  : 1101D - GCD Counting
// Category : DFS
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int MAX = 200005;
vvi g;
int n,ans;
vi a,divs[MAX];

void sieve() {
    for(int i = 2; i < MAX; i++)
        for(int j = i; j < MAX; j += i)
            divs[j].push_back(i);
}

vi dfs(int v, int p) {
    vi cur(divs[a[v]].size(), 1);
    for(int u : g[v]) {
        if(u == p)
            continue;
        vi son = dfs(u,v);
        vi &d1 = divs[a[v]], &d2 = divs[a[u]];
        for(int l = 0, r = 0; l < (int)d1.size(); l++) {
            while(r < d2.size() && d2[r] < d1[l]) r++;
            if(r < d2.size() && d2[r] == d1[l]) {
                ans = max(ans, cur[l]+son[r]);
                cur[l] = max(cur[l], son[r]+1);
            }
        }
    } 
    return cur;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    sieve();
    while(cin >> n) {
        a = vi(n); ans = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] > 1) ans = 1;
        }
        g = vvi(n);
        for(int i = 0; i < n-1; i++) {
            int x,y; cin >> x >> y; x--; y--;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs(0, -1);
        cout << ans << '\n';
    }
    return 0;
}