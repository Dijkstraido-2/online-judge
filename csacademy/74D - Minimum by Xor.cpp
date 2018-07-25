//============================================================================
// Problem  : 74D - Minimum by Xor
// Category : Brute force
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin >> n)
    {
        cout << (1 << n) - 1 << '\n';
        for(int m = 1; m < (1 << n); m++)
        {
            cout << __builtin_popcount(m) << '\n';
            for(int i = 0; i < n; i++)
                if(m & (1 << i))
                    cout << " " << i+1;
            cout << '\n';
        }
    }
    return 0;
}