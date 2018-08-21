//============================================================================
// Problem  : 1025A - Doggo Recoloring
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    string s;
    while(cin >> n >> s) 
    {
        int f[26] = {0};
        for(char c : s)
            f[c-'a']++;
        int ok = 0;
        for(int i = 0; i < 26; i++)
            if(f[i] > 1)
                ok = 1;
        cout << (ok || n == 1? "Yes" : "No") << '\n';
    }
    return 0; 
}