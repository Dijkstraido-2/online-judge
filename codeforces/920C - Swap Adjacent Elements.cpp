//============================================================================
// Judge    : 920C - Swap Adjacent Elements
// Category : Greedy
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,l,r,ok;
    vi v;
    string s;
    while(cin >> n)
    {
        v = vi(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        cin >> s; ok = 1;
        l = 0;
        while(l < n)
        {
            r = l;
            while(r < n && s[r] == '1')
                r++;
            for(int i = l; i <= r; i++)
                if(v[i] < l+1 || v[i] > r+1)
                    ok = 0;
            l = r+1;
        }
        cout << (ok? "YES" : "NO") << '\n';
    }
    return 0;
}