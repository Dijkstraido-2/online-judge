//============================================================================
// Problem  : 960A - Check the string
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s;
    while(cin >> s)
    {
        int invalid = 0, a = 0, b = 0, c = 0;
        for(int i = 0, turn = 0; i < s.size(); i++)
            if(turn == 0)
            {
                if(s[i] == 'a')
                    a++;
                else if(s[i] == 'b')
                {
                    b++;
                    turn = 1;
                }
                else
                    invalid = 1;
            }
            else if(turn == 1)
            {
                if(s[i] == 'a')
                    invalid = 1;
                else if(s[i] == 'b')
                    b++;
                else
                {
                    c++;
                    turn = 2;
                }
            }
            else 
            {
                if(s[i] == 'c')
                    c++;
                else
                    invalid = 1;
            }
        cout << (invalid || !a || !b || !c || (c != a && c != b)? "NO" : "YES") << '\n';
    }
    return 0;
}