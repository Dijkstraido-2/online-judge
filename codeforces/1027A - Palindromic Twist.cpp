//============================================================================
// Problem  : 1027A - Palindromic Twist
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T,n;
    string s;
    cin >> T;
    while(T--)
    {
        cin >> n >> s;
        int ok = 1;
        for(int l = 0, r = n-1; ok && l < r; l++, r--)
        {
            int d = abs(s[l]-s[r]);
            if(d != 0 && d != 2)
                ok = 0;
        }
        cout << (ok? "YES" : "NO") << '\n';
    }
    return 0;
}