//============================================================================
// Problem  : 962C - Make a Square
// Category : Brute force
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int INF = 20000000;
string s;
int n;

int solve(ll x)
{
    string t = to_string(x);
    int m = t.size(), pos = 0;
    for(int i = 0; i < n && pos < m; i++)
        if(s[i] == t[pos])
            pos++;
    return (pos == m)? (n - m) : INF; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> s)
    {
        n = s.size();
        int ans = INF;
        for(ll i = 1; i * i <= 2000000000LL; i++)
            ans = min(ans, solve(i*i));
        cout << (ans == INF? -1 : ans) << '\n';
    }
    return 0;
}