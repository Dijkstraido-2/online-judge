//============================================================================
// Problem  : 1023A - Single Wildcard Pattern Matching
// Category : Brute force
//============================================================================
#include <bits/stdc++.h>
using namespace std;

string get(const string &s, int l, int r) { return (r < l)? "" : s.substr(l, r-l+1); }

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    string s,t;
    while(cin >> n >> m >> s >> t)
    {
        int pos = -1, ok;
        for(int i = 0; i < n && pos == -1; i++)
            if(s[i] == '*')
                pos = i;
        if(pos == -1)
            ok = (s == t);
        else 
            ok = (m >= n-1) && get(s,0,pos-1) == get(t,0,pos-1) && get(s,pos+1,n-1) == get(t,m-n+pos+1,m-1);
        cout << (ok? "YES" : "NO") << '\n';
    }
    return 0;
}