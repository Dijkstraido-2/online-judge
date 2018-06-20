//============================================================================
// Problem  : 990B - Micro World
// Category : Sorting + Binary Search
//============================================================================
Copy
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
vi v;
vii p;
int n,k,ans;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> k)
    {
        v = vi(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        p = vii();
        for(int i = 1; i < n; i++)
            if(v[i] != v[i-1])
            {
                int lo = (int)(lower_bound(v.begin(), v.end(), v[i]-k) - v.begin());
                if(v[lo] < v[i])
                    p.push_back({lo,i-1});
            }
        if(p.empty()) 
            cout << n << '\n';
        else
        {
            ans = p[0].first + (n-1 - p.back().second);
            for(int i = 0; i < (int)p.size() - 1; i++)
                ans += max(p[i+1].first - p[i].second - 1, 0);
            cout << ans << '\n';
        }
    }
    return 0;
}