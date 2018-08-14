//============================================================================
// Judge    : 920B - Tea Queue
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T,n,l,r,maxi;
    vi ans;
    cin >> T;
    while(T--)
    {
        cin >> n;
        maxi = 0; ans = vi(n);
        for(int i = 0; i < n; i++)
        {
            cin >> l >> r;
            maxi = max(maxi + 1, l);
            ans[i] = (maxi > r? 0 : maxi);
            if(!ans[i]) maxi--;
        }
        for(int x : ans)
            cout << " " << x;
        cout << '\n';
    }
    return 0;
}