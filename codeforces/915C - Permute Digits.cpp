//============================================================================
// Problem  : 915C - Permute Digits
// Category : DP
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ii,vi> iivi;

string a,b;
int n,m;
map<iivi,int> mp;
vi memo;

int solve(int i, int c, vi f)
{
    if(i == n) return 1;
    if(mp.find({{i,c},f}) != mp.end()) return mp[{{i,c},f}];

    int ans = 0;
    for(int d = c? 9 : (b[i] - '0'); d >= (i? 0 : 1); d--)
        if(f[d])
        {
            int nc = c? 1 : (d == b[i] - '0'? 0 : 1);
            f[d]--;
            if(solve(i+1,nc,f))
            {
                ans = 1;
                memo[i] = d;
                break;
            }
            f[d]++;
        }
    mp[{{i,c},f}] = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    vi f;
    while(cin >> a >> b)
    {
        n = a.size();
        m = b.size();
        if(m > n)
        {
            sort(a.rbegin(), a.rend());
            cout << a << '\n';
        }
        else
        {
            mp.clear();
            memo = vi(n);
            f = vi(10,0);
            for(int i = 0; i < n; i++)
                f[a[i] - '0']++;
            solve(0,0,f);
            for(int i = 0; i < n; i++)
                cout << memo[i];
            cout << '\n';
        }
    }
    return 0;
}