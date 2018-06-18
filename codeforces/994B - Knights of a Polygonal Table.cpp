//============================================================================
// Problem  : 994B - Knights of a Polygonal Table
// Category : Greedy + Sortings 
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

struct knight {
    ll p,c,i;
};

bool operator < (const knight &a, const knight &b) {
    return a.p < b.p;
}

typedef vector<knight> vk;

vk v;
vi ans,cur;
ll n,k,coins;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> k)
    {
        v = vk(n);
        for(int i = 0; i < n; i++)
            cin >> v[i].p;
        for(int i = 0; i < n; i++) {
            cin >> v[i].c;
            v[i].i = i;
        }
        sort(v.begin(), v.end());
        ans = vi(n, 0); cur = vi(); coins = 0;
        for(int i = 0; i < n; i++)
        {
            ans[v[i].i] = v[i].c + coins;
            coins += v[i].c;
            cur.push_back(v[i].c);
            if(cur.size() > k)
            {
                ll mn = cur[0], pos = 0, m = cur.size();
                for(int j = 1; j < m; j++)
                    if(cur[j] < mn)
                    {
                        mn = cur[j];
                        pos = j;
                    }
                coins -= mn;
                swap(cur[pos], cur[m-1]);
                cur.pop_back();
            }
        }
        for(int i = 0; i < n; i++)
            cout << ans[i] << " \n"[i == n-1];
    }
    return 0;
}
