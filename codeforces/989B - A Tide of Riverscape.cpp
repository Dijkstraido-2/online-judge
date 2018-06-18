//============================================================================
// Problem  : 989B - A Tide of Riverscape
// Category : Constructive algorithms
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int same(char a, char b) { return (a == '1' && b == '1') || (a == '0' && b == '0'); }

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,p;
    string s;
    while(cin >> n >> p)
    {
        cin >> s;
        int ok = 0;
        for(int i = 0; i+p < n && !ok; i++)
            if(!same(s[i], s[i+p]))
            {
                ok = 1;
                if(s[i] == '.' && s[i+p] == '.')
                    s[i] = '1', s[i+p] = '0';
                else if(s[i] == '.')
                    s[i] = 1 - (s[i+p]-'0') + '0';
                else 
                    s[i+p] = 1 - (s[i]-'0') + '0';
            }
        if(!ok)
            cout << "No" << '\n';
        else
        {
            for(char c : s)
                cout << (c == '.'? '1' : c);
            cout << '\n';
        }
    }
    return 0;
}
