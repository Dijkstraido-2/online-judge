//============================================================================
// Judge    : 932A - Palindromic Supersequence
// Category : Basic Programming
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s,t;
    while(cin >> s)
    {
        t = s;
        reverse(t.begin(), t.end());
        cout << s + t << '\n';
    }
    return 0;
}