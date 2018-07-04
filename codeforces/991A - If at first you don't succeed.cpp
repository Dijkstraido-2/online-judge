//============================================================================
// Problem  : 991A - If at first you don't succeed
// Category : Brute force
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a,b,c,n,ans;
    while(cin >> a >> b >> c >> n)
    {
        ans = -1;
        for(int i = 0; i <= a; i++)
            for(int j = 0; j <= b; j++)
                if(a-i == b-j && a-i == c && n - (i+j+c) >= 1)
                    ans = n - (i+j+c);
        cout << ans << '\n';
    }
    return 0;
}