//============================================================================
// Problem  : 975A -  Aramic script
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,f[26];
    string s;
    set<string> st;
    while(cin >> n)
    {
        st.clear();
        for(int i = 0; i < n; i++)
        {
            cin >> s;
            memset(f, 0, sizeof f);
            for(char c : s)
                f[c-'a'] = 1;
            int m = 0;
            for(int i = 0; i < 26; i++)
                if(f[i])
                    s[m++] = 'a'+i;
            s.resize(m);
            st.insert(s);
        }
        cout << st.size() << '\n';
    }
    return 0;
}