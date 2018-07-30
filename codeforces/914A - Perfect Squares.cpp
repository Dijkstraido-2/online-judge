//============================================================================
// Problem  : 914A - Perfect Squares
// Category : Brute force
//============================================================================
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    set<int> st;
    int n,x,ans;
    for(int i = 0; i * i <= 1000000; i++)
        st.insert(i*i);
    while(cin >> n)
    {
        ans = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            if(st.find(x) == st.end())
                ans = max(ans, x);
        }
        cout << ans << '\n';
    }
    return 0;
}
