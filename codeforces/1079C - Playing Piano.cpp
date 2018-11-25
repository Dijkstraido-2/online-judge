//============================================================================
// Problem  : 1079C - Playing Piano
// Category : DP
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int n,dp[100005][5];
int v[100005],ans[100005];

int solve(int pos, int pre) {
    if(pos == n) return 1;
    if(dp[pos][pre] != -1) return dp[pos][pre];
    int ok = 0;
    for(int cur = 0; cur < 5 && !ok; cur++)
        if(((v[pos-1] < v[pos] && pre < cur) || 
            (v[pos-1] > v[pos] && pre > cur) ||
            (v[pos-1] == v[pos] && pre != cur)) && solve(pos+1,cur)) {
            ok = 1;
            ans[pos] = cur; 
        } 
    return dp[pos][pre] = ok;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n) {
        for(int i = 0; i < n; i++)
            cin >> v[i];
        memset(dp, -1, sizeof dp);
        int ok = 0;
        for(int i = 0; i < 5 && !ok; i++)
            if(solve(1,i)) {
                cout << i+1;
                for(int i = 1; i < n; i++)
                    cout << " " << ans[i]+1;
                cout << '\n';
                ok = 1;
            }
        if(!ok)
            cout << -1 << '\n';
    }
    return 0;
}