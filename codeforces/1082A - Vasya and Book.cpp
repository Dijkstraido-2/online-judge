//============================================================================
// Problem  : 1082A - Vasya and Book
// Category : Math
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll q,n,x,y,d,ans,INF = 2e9+5;
    cin >> q;
    while(q--) {
        cin >> n >> x >> y >> d; ans = INF;
        if(x%d == y%d) 
            ans = min(ans, labs(y-x)/d);
        if(y%d == 1)
            ans = min(ans, (ll)ceil((x-1)*1./d) + (y-1)/d);
        if(n%d == y%d)
            ans = min(ans, (ll)ceil((n-x)*1./d) + (n-y)/d);
        cout << (ans == INF? -1 : ans) << '\n';
    }
    return 0;
}