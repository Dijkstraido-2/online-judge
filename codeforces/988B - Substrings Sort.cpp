//============================================================================
// Problem  : 988B - Substrings Sort
// Category : Sortings
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;

vs v;
int n;

bool cmp(const string &a, const string &b)
{
    int n = a.size(), m = b.size();
    for(int i = 0; i + n <= m; i++)
        if(b.substr(i, n) == a)
            return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n)
    {
        v = vs(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end(), cmp);
        int ok = 1;
        for(int i = 0; i < n-1; i++)
            if(!cmp(v[i], v[i+1]))
                ok = 0;
        cout << (ok? "YES" : "NO") << '\n';
        if(ok)
            for(auto s : v)
                cout << s << '\n';
    }
    return 0;
}