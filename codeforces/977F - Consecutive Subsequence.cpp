//============================================================================
// Problem  : 977F - Consecutive Subsequence
// Category : DP
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vi v,ans;
int n;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    map<int,int> mp;
    while(cin >> n)
    {
        v = vi(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        mp.clear();
        for(int i = 0; i < n; i++)
            mp[v[i]] = max(mp[v[i]], mp[v[i]-1] + 1);
        int mx = 0, id = -1;
        for(auto it : mp)
            if(it.second > mx)
            {
                mx = it.second;
                id = it.first;
            }
        ans = vi();
        for(int i = n-1; i >= 0; i--)
            if(v[i] == id)
            {
                ans.push_back(i);
                id--;
            }
        reverse(ans.begin(), ans.end());
        cout << mx << '\n';
        for(int x : ans)
            cout << " " << x+1;
        cout << '\n';
    }
    return 0;
}