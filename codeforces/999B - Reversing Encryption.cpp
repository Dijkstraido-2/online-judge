//============================================================================
// Problem  : 999B - Reversing Encryption
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
        for(int i = 2; i <= n; i++)
            if(n % i == 0)
                reverse(s.begin(), s.begin()+i);
        cout << s << '\n';
    }
    return 0;
}