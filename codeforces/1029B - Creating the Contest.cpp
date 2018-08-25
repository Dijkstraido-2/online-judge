//============================================================================
// Problem  : 1029B - Creating the Contest
// Category : Greedy
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin >> n)
    {
        int last = -1, cont = 0, ans = 1;
        for(int i = 0; i < n; i++)
        {
            int x; cin >> x;
            if(last == -1 || x <= last*2)
                cont++;
            else 
                cont = 1;
            ans = max(ans, cont);
            last = x;
        }
        cout << ans << '\n';
    }
    return 0;
}