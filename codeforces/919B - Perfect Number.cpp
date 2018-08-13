//============================================================================
// Judge    : 919B - Perfect Number
// Category : Brute force
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
vi v;
int k;

void init()
{
    for(ll i = 19; (int)v.size() <= 10000; i++)
    {
        ll n = i, s = 0;
        while(n)
        {
            s += (n % 10);
            n /= 10;
            if(s > 10)
                break;
        }
        if(s == 10)
            v.push_back(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    init();
    while(cin >> k)
        cout << v[k-1] << '\n';
    return 0;
} 