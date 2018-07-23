//============================================================================
// Problem  : 78D - Expected Lcp
// Category : Trie
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1000005;

ll getComb2(ll n) { return n*(n-1)/2; }

struct Trie {
    int t[MAX][26],n;
    int f[MAX][26];
    
    Trie() { clear(); }
    
    int create() 
    {
        memset(t[n], -1, sizeof t[n]); 
        memset(f[n], 0, sizeof f[n]); 
        return n++;
    }
    
    void clear() { n = 0; create(); }
    
    void insert(const string &s)
    {
        int cur = 0;
        for(char c : s)
        {
            if(t[cur][c-'a'] == -1)
                t[cur][c-'a'] = create();
            f[cur][c-'a']++;
            cur = t[cur][c-'a'];
        }
    }
    
    ll solve(int cur = 0)
    {
        ll ans = 0;
        for(int i = 0; i < 26; i++)
        {
            ans += getComb2(f[cur][i]);
            if(t[cur][i] != -1)
                ans += solve(t[cur][i]);
        }
        return ans;
    }
}t;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    string s;
    while(cin >> n)
    {
        t.clear();
        for(int i = 0; i < n; i++)
        {
            cin >> s;
            t.insert(s);
        }
        cout << fixed << setprecision(8) << t.solve() * 1. / getComb2(n) << '\n';
    }
    return 0;
}