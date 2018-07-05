//============================================================================
// Problem  : 979B - Treasure Hunt
// Category : Greedy
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t,n,mx[3];
    string s;
    map<char,int> mp;
    while(cin >> t)
    {
        for(int i = 0; i < 3; i++)
        {
            cin >> s; n = s.size(); mp.clear();
            for(char c : s)
                mp[c]++;
            mx[i] = 0;
            for(auto it : mp)
                mx[i] = max(mx[i], it.second);
        }
        for(int i = 0; i < 3; i++)
            mx[i] = (mx[i] == n && t == 1)? n-1 : min(mx[i]+t, n);
        if(mx[0] > mx[1] && mx[0] > mx[2])
            cout << "Kuro" << '\n';
        else if(mx[1] > mx[0] && mx[1] > mx[2])
            cout << "Shiro" << '\n';
        else if(mx[2] > mx[0] && mx[2] > mx[1])
            cout << "Katie" << '\n';
        else
            cout << "Draw" << '\n';
    }    
    return 0;
}