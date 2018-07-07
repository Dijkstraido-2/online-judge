//============================================================================
// Problem  : 977C - Less or Equal
// Category : Sortings
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vi v;
int n,k;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> k)
    {
        v = vi(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        if(k == 0)
            cout << (v[0]-1 <= 0? -1 : (v[0]-1)) << '\n';
        else if(k == n)
            cout << v[n-1] << '\n';
        else 
        {
            map<int,int> mp;
            for(int i = 0; i < n; i++)
                mp[v[i]]++;
            int s = 0, ans = -1;
            for(auto it : mp)
            {
                s += it.second;
                if(s == k)
                {
                    ans = it.first;
                    break;
                }
            } 
            cout << ans << '\n';
        }
    }
    return 0;
}