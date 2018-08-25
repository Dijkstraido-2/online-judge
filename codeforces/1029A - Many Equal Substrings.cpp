//============================================================================
// Problem  : 1029A - Many Equal Substrings
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,k;
    string s;
    while(cin >> n >> k >> s)
    {
        int pos = -1;
        for(int i = 1; i < n; i++)
            if(s.substr(0,i) == s.substr(n-i,i))
                pos = i;
        string suf = (pos == -1? s : s.substr(pos, n-pos));
        cout << s;
        for(int i = 1; i < k; i++)
            cout << suf;
        cout << '\n';
    }
    return 0;
}