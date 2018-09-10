//============================================================================
// Judge    : 931A - Friends Meeting
// Category : Brute force
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int solve(int x) { return x*(x+1)/2; }

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a,b,pa,pb,ans;
    while(cin >> pa >> pb)
    {
        a = min(pa, pb); b = max(pa, pb);
        ans = INT_MAX;
        for(int i = a; i <= b; i++)
            ans = min(ans, solve(i-a)+solve(b-i));
        cout << ans << '\n';
    }
    return 0;
}