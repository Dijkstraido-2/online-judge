//============================================================================
// Problem  : 996A - Hit the Lottery
// Category : Greedy
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,ans;
    int d[5] = {1,5,10,20,100};
    while(cin >> n)
    {
        ans = 0;
        for(int i = 4; i >= 0; i--)
        {
            ans += n/d[i];
            n %= d[i];
        }
        cout << ans << '\n';
    }
    return 0;
}