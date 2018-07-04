//============================================================================
// Problem  : 984A - Game
// Category : Sorting
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vi v;
int n;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n)
    {
        v = vi(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        if(n % 2 != 0)
            cout << v[n/2] << '\n';
        else
            cout << v[n/2 - 1] << '\n';
    }
    return 0;
}