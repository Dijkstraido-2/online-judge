//============================================================================
// Problem  : 1016B - Segment Occurrences
// Category : Binary Search
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,q,l,r;
    string s,t;
    vi v;
    while(cin >> n >> m >> q >> s >> t)
    {
        v.clear();
        for(int i = 0; i <= n-m; i++)
            if(s.substr(i,m) == t)
                v.push_back(i);
        while(q--)
        {
            cin >> l >> r; l--; r--;
            r -= m-1;
            cout << max(0, (int)(upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l))) << '\n';
        }
    }
    return 0; 
}