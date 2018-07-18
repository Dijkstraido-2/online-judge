//============================================================================
// Problem  : 83A - License Plates
// Category : Basic Programming
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s;
    int ans = 1;
    cin >> s;
    for(int i = 0; i < (int)s.size(); i++)
        if(s[i] == 'd') 
            ans *= (!i || s[i-1] != 'd'? 10 : 9);
        else if(s[i] == 'c') 
            ans *= (!i || s[i-1] != 'c'? 26 : 25);
    cout << ans << '\n';
    return 0;
}