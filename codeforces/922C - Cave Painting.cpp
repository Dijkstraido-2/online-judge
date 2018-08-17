//============================================================================
// Judge    : 922C - Cave Painting
// Category : Math (Number Theory)
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n,k,found;
    set<ll> st;
    while(cin >> n >> k)
        if(k >= 43)
            cout << "No" << '\n';
        else 
        {
            st.clear(); found = 0;
            for(int i = 1; i <= k && !found; i++)
                if(st.count(n % i))
                    found = 1;
                else
                    st.insert(n % i);
            cout << (found? "No" : "Yes") << '\n';
        }
    return 0;
}