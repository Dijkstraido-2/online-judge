//============================================================================
// Problem  : 959A - Mahmoud and Ehab and the even-odd game
// Category : Basic Programming
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin >> n)
        cout << (n % 2? "Ehab" : "Mahmoud") << '\n';
    return 0;
}