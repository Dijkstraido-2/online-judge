//============================================================================
// Problem  : 80A - IOI Selection
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vi v(16);

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    for(int i = 0; i < 16; i++)
        cin >> v[i];
    int ans = 4;
    for(int i = 4; i < 16; i++)
        if(v[i] + 300 > v[3])
            ans++;
    cout << ans << '\n';
    return 0;
}