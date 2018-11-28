//============================================================================
// Problem  : 1077C - Good Array
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n,sum,maxi,pos,maxi2;
    vi v;
    while(cin >> n) {
        v = vi(n); sum = 0; maxi = maxi2 = 0; pos = -1;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            sum += v[i];
            if(v[i] > maxi) {
                maxi2 = maxi;
                maxi = v[i]; 
                pos = i;
            } else if(v[i] > maxi2) 
                maxi2 = v[i];
        }
        vi ans;
        for(int i = 0; i < n; i++) 
            if(sum-v[i] == 2*(i==pos? maxi2 : maxi))
                ans.push_back(i+1);
        cout << ans.size() << '\n';
        for(auto x : ans) 
            cout << " " << x;
        cout << '\n';
    }
    return 0;
}