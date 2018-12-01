//============================================================================
// Problem  : 1082C - Multi-Subject Competition
// Category : DP
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    vii v;
    while(cin >> n >> m) {
        v = vii(n);
        for(int i = 0; i < n; i++)
            cin >> v[i].first >> v[i].second;
        sort(v.rbegin(), v.rend());
        int last = 0,cont,sum,ans=0;
        vector<int> dp(n+1,0);
        for(auto p : v) {
            if(p.first != last) {
                last = p.first;
                cont = sum = 0;
            } 
            cont++; sum += p.second;
            if(sum > 0) 
                dp[cont] += sum;
            ans = max(ans, dp[cont]);
        }
        cout << ans << '\n';
    }
    return 0;
}