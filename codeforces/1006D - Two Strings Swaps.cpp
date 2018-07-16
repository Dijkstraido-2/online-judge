//============================================================================
// Problem  : 1006D - Two Strings Swaps
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s,t;
    int n,l,r,ans;
    while(cin >> n) 
    {
        cin >> s >> t;
        l = 0; r = n-1; ans = 0;
        while(l <= r) 
        {
            if(l == r) 
                ans += (s[l] != t[l]);
            else {
                if(t[l] == t[r])
                    ans += (s[l] != s[r]);
                else 
                {
                    if(s[l] == s[r]) 
                        ans += (s[l] == t[l] || s[l] == t[r])? 1 : 2;
                    else 
                    {
                        if((s[l] == t[l] && s[r] == t[r]) || (s[l] == t[r] && s[r] == t[l]))
                            ans += 0;
                        else if(s[l] == t[l] || s[l] == t[r] || s[r] == t[l] || s[r] == t[r])
                            ans += 1;
                        else
                            ans += 2;
                    }
                }
            }
            l++; r--;
        }
        cout << ans << '\n';
    }
    return 0;
}