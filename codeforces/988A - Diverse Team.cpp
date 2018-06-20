//============================================================================
// Problem  : 988A - Diverse Team
// Category : Brute force
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,k,x;
    map<int,int> mp;
    while(cin >> n >> k)
    {
        mp.clear();
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            mp[x] = i+1;
        }
        cout << (mp.size() >= k? "YES" : "NO") << '\n';
        if(mp.size() >= k)
        {
            auto it = mp.begin();
            for(int i = 0; i < k; i++, it++)
                cout << it->second << " \n"[i == k-1];
        }
    }
    return 0;
}