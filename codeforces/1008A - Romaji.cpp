//============================================================================
// Problem  : 1008A - Romaji
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int isVowel(char c) { return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s;
    int n,ok;
    while(cin >> s)
    {
        n = s.size(); ok = s[n-1] == 'n' || isVowel(s[n-1]);
        for(int i = 0; i < n-1; i++)
            if(!isVowel(s[i]) && s[i] != 'n' && !isVowel(s[i+1]))
                ok = 0;
        cout << (ok? "YES" : "NO") << '\n';
    }
    return 0;
}