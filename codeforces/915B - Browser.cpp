//============================================================================
// Problem  : 915B - Browser
// Category : Greedy
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,pos,l,r,ans1,ans2,cur;
    while(cin >> n >> pos >> l >> r)
    {
        // Pos -> Left -> Right
        cur = pos;
        ans1 = 0;
        if(l > 1)
        {
            ans1 += abs(cur - l) + 1;
            cur = l;
        }
        if(r < n)
        {
            ans1 += abs(r - cur) + 1;
            cur = r;
        }
        // Pos -> Right -> Left
        cur = pos;
        ans2 = 0;
        if(r < n)
        {   
            ans2 += abs(r - cur) + 1;
            cur = r;
        }
        if(l > 1)
        {
            ans2 += abs(cur - l) + 1;
            cur = l;
        }
        cout << min(ans1, ans2) << '\n';
    }
    return 0;
}