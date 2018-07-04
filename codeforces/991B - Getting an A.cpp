//============================================================================
// Problem  : 991B - Getting an A
// Category : Greedy+Sortings
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vi v;
int n,s,cur;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n)
    {
        v = vi(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        s = accumulate(v.begin(), v.end(), 0); cur = 0;
        while((int)((s*1./n) + 0.5) < 5)
            s += -v[cur++] + 5; 
        cout << cur << '\n';
    }
    return 0;
}