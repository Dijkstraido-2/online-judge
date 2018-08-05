//============================================================================
// Problem  : 914F - Substrings in a String
// Category : Bitset
//============================================================================
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5+5;
bitset<MAX> f[26];

// gets [l,r] from bitset
bitset<MAX> split(const bitset<MAX>& f, int l, int r) {
    return (f << MAX-(r+1)) >> (MAX-(r-l+1)); 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s,t;
    char c;
    int q,op,x,l,r;
    while(cin >> s >> q) 
    {
        for(int i = 0; i < 26; i++) f[i].reset();
        for(int i = 0; i < (int)s.size(); i++)
            f[s[i]-'a'][i] = 1;
        while(q--) 
        {
            cin >> op;
            if (op == 1) 
            {
                cin >> x >> c; x--;
                f[s[x]-'a'][x] = 0;
                s[x] = c;
                f[s[x]-'a'][x] = 1;
            }
            else 
            {
                cin >> l >> r >> t; l--; r--;
                bitset<MAX> g; g.set();
                for(int i = 0; i < (int)t.size(); i++)
                    g &= split(f[t[i]-'a'],l,r) >> i;
                cout << g.count() << "\n";
            }
        }
    }
    return 0; 
}