//============================================================================
// Problem  : 78A - Spring Love
// Category : Basic Programming
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,x,s = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
       cin >> x;
       s += x;
    }
    cout << (s % 2 != 0) << '\n';
    return 0;
}