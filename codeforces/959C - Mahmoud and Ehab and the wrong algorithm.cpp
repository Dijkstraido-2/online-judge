//============================================================================
// Problem  : 959C - Mahmoud and Ehab and the wrong algorithm
// Category : Constructive algorithms
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin >> n)
    {
        // incorrect
        if(n <= 5)
            cout << -1 << '\n';
        else
        {
            cout << 1 << " " << 2 << '\n';
            for(int i = 3, left = (n-2)/2; i <= n; i++, left--)
                if(left > 0)
                    cout << 1 << " " << i << '\n';
                else
                    cout << 2 << " " << i << '\n';
        }
        // correct
        for(int i = 1; i < n; i++)
            cout << i << " " << i+1 << '\n';
    }
    return 0;
}