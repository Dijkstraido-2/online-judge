//============================================================================
// Problem  : 1006A - Adjacent Replacements
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,x;
    while(cin >> n) 
    {
        for(int i = 0; i < n; i++) 
        {
            cin >> x;
            cout << (x%2==0? x-1 : x) << " ";
        }
        cout << '\n';
    }
    return 0;
}