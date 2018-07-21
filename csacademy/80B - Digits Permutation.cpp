//============================================================================
// Problem  : 80B - Digits Permutation
// Category : Brute force
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s;
    int a,b,ans;
    while(cin >> s >> b)
    {
        sort(s.begin(), s.end());
        ans = -1;
        do{
            a = stoi(s);
            if(s[0] != '0' && a <= b)
                ans = max(ans, a);
        }while(next_permutation(s.begin(), s.end()));
        cout << ans << '\n';
    }
    return 0;
}