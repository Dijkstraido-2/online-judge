#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<string> vs;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll ntest=1,T,n,k,v,lo,hi;
    vs s;
    cin >> T;
    while(T--)
    {
        cin >> n >> k >> v; 
        s = vs(n);
        for(int i = 0; i < n; i++)
            cin >> s[i];
        lo = (k*(v-1)) % n; hi = (lo+k-1) % n;
        cout << "Case #" << ntest++ << ":";
        if(lo <= hi)
            for(int i = lo; i <= hi; i++)
                cout << " " << s[i];
        else
        {
            for(int i = 0; i <= hi; i++)
                cout << " " << s[i];
            for(int i = lo; i < n; i++)
                cout << " " << s[i];
        }
        cout << '\n';
    }
    return 0;
}
