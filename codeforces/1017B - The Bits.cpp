//============================================================================
// Problem  : 1017B - The Bits
// Category : Math
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n,a1,a2,b1,b2;
    string s,t;
    while(cin >> n >> s >> t)
    {
        a1 = a2 = b1 = b2 = 0;
        for(int i = 0; i < n; i++)
            if(s[i] == '0' && t[i] == '1')
                a1++;
            else if(s[i] == '0' && t[i] == '0')
                a2++;
            else if(s[i] == '1' && t[i] == '1')
                b1++;
            else if(s[i] == '1' && t[i] == '0')
                b2++;
        cout << a2*b1 + a1*b2 + a2*b2 << '\n';
    }
    return 0;
}