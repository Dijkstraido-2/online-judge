//============================================================================
// Problem  : 915E - Physical Education Lessons
// Category : Set
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,q,l,r,k;
    cin >> n >> q;
    set<pair<int,int>> st;
    int ans = n;
    while(q--) 
    {
        cin >> l >> r >> k;
        auto it = st.lower_bound({l,0});
        while(it != st.end()) 
        {
            int L = it->second, R = it->first;
            int w = min(r,R) - max(l,L) + 1; // intersection
            if(w <= 0)
                break;
            ans += w;
            st.erase(it++);
            if(L < l)
                st.insert({l-1, L});
            if(r < R)
                st.insert({R, r+1});
        }
        if(k == 1)
            st.insert({r,l}), ans -= r-l+1;
        cout << ans << "\n";
    }
    return 0;
}