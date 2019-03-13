//============================================================================
// Problem  : AGC 1 C - Shorten Diameter
// Category : Brute force
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
const int INF = 2000000;
vvi t;
int n,k;

int solve(int x, int y = -1) {
    vi dis(n, INF); dis[x] = 0;
    queue<int> q; q.push(x);
    int maxd = k/2;
    if(y != -1) {
        dis[y] = 0; q.push(y);
        maxd = (k-1)/2;
    }
    int ans = 0;
    while(!q.empty()) {
        int v = q.front(); q.pop();
        if(dis[v] > maxd)
            ans++;
        for(auto u : t[v]) {
            if(dis[u] == INF) {
                dis[u] = dis[v] + 1;
                q.push(u);
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> k) {
        t = vvi(n);
        for(int i = 0; i < n-1; i++) {
            int x,y; cin >> x >> y; x--; y--;
            t[x].push_back(y);
            t[y].push_back(x);
        }
        int ans = n;
        for(int v = 0; v < n; v++) {
            ans = min(ans, solve(v));
            for(auto u : t[v]) {
                ans = min(ans, solve(v,u));
            }
        }
        cout << ans << '\n';
    }
    return 0;
}