//============================================================================
// Problem  : 913D - Too Easy Problems
// Category : Binary Search (the answer) 
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct exam
{
    int a,i;
    ll t;
    exam() {}
    exam(int pa, ll pt, int pi) : a(pa), t(pt), i(pi) {}
}; 

bool operator < (const exam &p, const exam &q)
{
    if(p.t != q.t)
        return p.t < q.t;
    else
        return p.a < q.a;
}

typedef vector<exam> ve;
typedef vector<int> vi;

ve v;
int n;
ll t;
vi ans;

bool can(int k)
{
    ll sum = 0;
    int cont = 0;
    for(int i = 0; i < n; i++)
        if(v[i].a >= k)
        {
            sum += v[i].t;
            if(sum <= t)
                cont++;
        }
    return cont >= k;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int lo,hi,mid;
    while(cin >> n >> t)
    {
        v = ve(n); 
        for(int i = 0; i < n; i++)
        {
            cin >> v[i].a >> v[i].t;
            v[i].i = i+1;
        }
        sort(v.begin(), v.end());
        lo = 0; hi = n; 
        while(lo < hi)
        {
            mid = lo + (hi-lo+1) / 2;
            if(can(mid))
                lo = mid;
            else
                hi = mid-1;
        }
        cout << lo << '\n';
        if(lo == 0)
            cout << 0 << '\n';
        else
        {
            ll sum = 0;
            ans = vi();
            for(int i = 0; i < n && (int)ans.size() < lo; i++)
                if(v[i].a >= lo)
                {
                    sum += v[i].t;
                    if(sum <= t)
                        ans.push_back(v[i].i);
                }
            cout << ans.size() << '\n';
            bool first = true;
            for(int x : ans)
            {
                if(!first) cout << " ";
                first = false;
                cout << x;
            }
            cout << '\n'; 
        }
    }
    return 0;
} 