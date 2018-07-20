//============================================================================
// Problem  : 79C - K Inversions
// Category : Treaps
//============================================================================
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

template <class T> using Tree = 
tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
Tree<ll> t;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n,k;
    while(cin >> n >> k)
    {
        t.clear();
        for(int i = 0; i < n; i++)   
            t.insert(i+1);
        for(int i = 0; i < n; i++)
        {
            ll com = (n-1-i)*(n-2-i)/2;
            ll pos = min(max(0LL, k - com), (ll)t.size() - 1);
            ll x = *t.find_by_order(pos);
            cout << x << " ";
            t.erase(x);
        }
    }
    return 0;
}