//============================================================================
// Problem  : 916C - Jamie and Interesting Graph
// Category : Math
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef pair<ll,ii> iii;
typedef vector<iii> viii;

const int MAX = 1000005;
bitset<MAX> bs;
vi primes;

void sieve()
{
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2; i < MAX; i++)
        if(bs[i])
        {
            for(ll j = i * i; j < MAX; j += i)
                bs[j] = 0;
            primes.push_back(i);
        }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    sieve();
    int n,m;
    ll x;
    viii ans;
    while(cin >> n >> m)
    {
        ans = viii(); 
        for(int i = 2; i <= n - 1; i++)
            ans.push_back({2,{1,i}}); // n-2 edges with weight 2
        for(int i = 0; i < (int)primes.size(); i++)
            if(bs[2*(n-2) + primes[i]])
            {
                x = primes[i];
                ans.push_back({x, {1, n}});
                break;
            }
        if((int)ans.size() < m)
        {
            bool finished = false;
            for(int i = 2; i <= n && !finished; i++)
                for(int j = i + 1; j <= n && !finished; j++)
                {
                    ans.push_back({x+1, {i, j}});
                    if((int)ans.size() == m)
                        finished = true;
                }
        }
        cout << x << " " << 2*(n-2) + x << '\n';
        for(auto p : ans)
            cout << p.second.first << " " << p.second.second << " " << p.first << '\n'; 
    }
    return 0;
}