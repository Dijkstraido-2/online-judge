//============================================================================
// Problem  : 989A - A Blend of Springtime
// Category : Implementation 
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int f[105][3],n;
string s;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> s)
    {
        memset(f, 0, sizeof f);
        n = s.size();
        for(int i = 1; i <= n; i++)
            if(s[i-1] != '.')
                f[i-1][s[i-1]-'A'] = f[i][s[i-1]-'A'] = f[i+1][s[i-1]-'A'] = 1;
        int ans = 0;
        for(int i = 1; i <= n; i++)
            ans = (ans || (f[i][0] && f[i][1] && f[i][2]));
        cout << (ans? "Yes" : "No") << '\n';
    }
    return 0;
}
