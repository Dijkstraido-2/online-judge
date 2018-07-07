//============================================================================
// Problem  : 978A - Remove Duplicates
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    vi v,ans;
    set<int> st;
    while(cin >> n)
    {
        v = vi(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        reverse(v.begin(), v.end());
        ans.clear(); st.clear();
        for(int i = 0; i < n; i++)
        {
            if(st.find(v[i]) == st.end())
                ans.push_back(v[i]);
            st.insert(v[i]);
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for(int x : ans)
            cout << x << " ";
        cout << '\n';
    }
    return 0;
}