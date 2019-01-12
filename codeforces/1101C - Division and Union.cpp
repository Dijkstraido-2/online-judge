//============================================================================
// Problem  : 1101C - Division and Union
// Category : Sorting
//============================================================================
#include <bits/stdc++.h>
using namespace std;

struct seg { int x,i,t; };
bool operator < (const seg &a, const seg &b) { return (a.x != b.x)? a.x < b.x : a.t < b.t; }

typedef vector<seg> vs;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int q,n,color;
    vs v;
    cin >> q;
    while(q--) {
        cin >> n; 
        v.clear();
        for(int i = 0; i < n; i++) {
            int l,r; cin >> l >> r;
            v.push_back({l,i,0});
            v.push_back({r,i,1});
        }
        sort(v.begin(), v.end());
        deque<seg> dq; color = 0;
        vector<int> ans(n,-1), rem(n,0);
        for(auto cur : v) {
            if(cur.t == 0) {
                ans[cur.i] = (dq.empty()? color++ : ans[dq.front().i]); 
                dq.push_back(cur);
            } else {
                rem[cur.i] = 1;
            }
            while(!dq.empty() && rem[dq.front().i]) {
                dq.pop_front();
            }
        }
        if(color <= 1) {
            cout << -1 << '\n';
        } else {
            for(int i : ans) {
                cout << " " << (i&1? 1 : 2);
            }
            cout << '\n';
        }
    }
    return 0;
}