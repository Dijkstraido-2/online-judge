//============================================================================
// Problem  : 988E - Divisibility by 25
// Category : Greedy
//============================================================================
#include <bits/stdc++.h>
using namespace std;

const int INF = 2000000;

int n;

int solve(string s, string t)
{
    if(n == 1) return INF;
    int ans = 0;
    for(int k = 0; k <= 1; k++)
        if(s[n-1-k] != t[1-k])
        {
            int pos = -1;
            for(int i = n-1-k; i >= 0 && pos == -1; i--)
                if(s[i] == t[1-k])
                    pos = i;
                else
                    ans++;
            if(pos == -1)
                return INF;
            for(int i = pos; i < n-1-k; i++)
                swap(s[i], s[i+1]);
        }
    int pos = 0;
    while(pos < n && s[pos] == '0')
        pos++, ans++;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s;
    int ans;
    while(cin >> s)
    {
        n = s.size(); ans = INF;
        ans = min(ans, solve(s, "00"));
        ans = min(ans, solve(s, "25"));
        ans = min(ans, solve(s, "50"));
        ans = min(ans, solve(s, "75"));
        cout << (ans == INF? -1 : ans) << '\n';
    }
    return 0;
}