//============================================================================
// Problem  : 990C - Bracket Sequences Concatenation Problem
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<char> vc;

int n,m;
map<int,ll> mp;
string s;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n)
    {
        mp.clear();
        for(int i = 0; i < n; i++)
        {
            cin >> s; 
            vc st;
            for(char c : s)
                if(c == '(')
                    st.push_back(c);
                else if(c == ')')
                {
                    if(!st.empty() && st.back() == '(')
                        st.pop_back();
                    else
                        st.push_back(c);
                }
            if(st.empty())
                mp[0]++;
            else
            {
                m = st.size();
                if(st.front() == st.back())
                {
                    if(st.front() == ')')
                        mp[m]++;
                    else
                        mp[-m]++; 
                }
            }
        }
        ll ans = mp[0] * mp[0];
        for(auto it : mp)
            if(it.first < 0 && mp.find(-1 * it.first) != mp.end())
                ans += mp[it.first] * mp[-1 * it.first];
        cout << ans << '\n';
        
    }
    return 0;
}