//============================================================================
// Problem  : 1005B - Delete from the Left
// Category : Brute force
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s,t;
    while(cin >> s >> t)
    {
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        int n = s.size(), m = t.size(), k = 0;
        while(k < n && k < m && s[k] == t[k])
            k++;
        cout << n-k + m-k << '\n';
    }
    return 0;
}