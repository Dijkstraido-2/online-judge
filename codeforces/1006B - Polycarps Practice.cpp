//============================================================================
// Problem  : 1006B - Polycarps Practice
// Category : Greedy+Sorting
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,k,d[2005],sum;
    vii v;
    vi pos;
    while(cin >> n >> k) 
    {
        v.clear();
        for(int i = 0; i < n; i++) 
        {
            cin >> d[i];
            v.push_back({d[i],i});
        }
        sort(v.rbegin(), v.rend()); pos.clear();
        sum = 0;
        for(int i = 0; i < k; i++) 
        {
            sum += v[i].first;
            pos.push_back(v[i].second);
        }
        cout << sum << '\n';
        sort(pos.begin(), pos.end());
        int cur = 0;
        for(int i = 0; i < k-1; i++) 
        {
            cout << pos[i]-cur+1 << " ";
            cur = pos[i]+1;
        }
        cout << n-cur << '\n';
    }
    return 0;
}