//============================================================================
// Problem  : 1025C - Plasticine zebra
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s;
    int n,ans;
    while(cin >> s)
    {
        n = s.size(); s += s; ans = 1;
        for(int i = 0; i < n; i++)
        {
            int nxt = i+1, cont = 1;
            while(nxt < 2*n && s[nxt] != s[nxt-1]) 
            {
                nxt++;
                cont++;
            }
            i = nxt-1;
            ans = max(ans, min(cont, n));
        }
        cout << ans << '\n';
    }
    return 0;
}