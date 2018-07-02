//============================================================================
// Problem  : 987A - Infinity Gauntlet
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,string> ii;
map<string,ii> mp;
int n;
string s;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n)
    {
        mp.clear(); 
        mp["purple"] = {1,"Power"};
        mp["green"] = {1,"Time"};
        mp["blue"] = {1,"Space"};
        mp["orange"] = {1,"Soul"};
        mp["red"] = {1,"Reality"};
        mp["yellow"] = {1,"Mind"};

        for(int i = 0; i < n; i++)
        {
            cin >> s;
            mp[s].first = 0;
        }
        int ans = 0;
        for(auto it : mp)
            if(it.second.first)
                ans++;
        cout << ans << '\n';
        for(auto it : mp)
            if(it.second.first)
                cout << it.second.second << '\n';
    }
    return 0;
}