//============================================================================
// Problem  : 977B - Two-gram
// Category : Map
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,mx;
    string s,ans;
    map<string,int> mp;
    while(cin >> n >> s)
    {
        mp.clear();
        for(int i = 0; i < n-1; i++)
            mp[s.substr(i,2)]++;
        mx = 0; ans = "";
        for(auto it : mp)
            if(it.second > mx)
            {
                mx = it.second;
                ans = it.first;
            }
        cout << ans << '\n';
    }
    return 0;
}