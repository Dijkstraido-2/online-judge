//============================================================================
// Problem  : 978B - File Name
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,cont,ans;
    string s;
    while(cin >> n >> s)
    {
        cont = ans = 0;
        for(char c : s)
            if(c == 'x')
            {
                cont++;
                if(cont >= 3)
                    ans++;
            }
            else
                cont = 0;
        cout << ans << '\n';
    }
    return 0;
}