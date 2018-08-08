//============================================================================
// Judge    : 917A/918C - The Monster
// Category : Brute force
//============================================================================
#include <bits/stdc++.h>
using namespace std;

string s;
int n;
int ok[5005][5005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a,b,c,ans;
    while(cin >> s)
    {
        n = s.size();
        memset(ok, 0, sizeof ok);
        for(int i = 0; i < n; i++)
        {
            a = b = c = 0;
            for(int j = i; j < n; j++)
            {
                (s[j] == '(')? a++ : (s[j] == ')'? b++ : c++);
                if(b > a + c)
                    break;
                ok[i][j] = ((j - i + 1) % 2 == 0);
            }
        }
        ans = 0;
        for(int j = n - 1; j >= 0; j--)
        {
            a = b = c = 0;
            for(int i = j; i >= 0; i--)
            {
                (s[i] == '(')? a++ : (s[i] == ')'? b++ : c++);
                if(a > b + c)
                    break;
                ans += ok[i][j];
            }
        }
        cout << ans << '\n';
    }
    return 0;
} 