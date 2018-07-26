//============================================================================
// Judge    : 73A - Three Equal
// Category : Brute force
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int cost[3];
    int n,x;
    while(cin >> n)
    {
        cost[0] = cost[1] = cost[2] = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            for(int j = 0; j < 3; j++)
                cost[(x+j) % 3] += j;
        }
        cout << min(cost[0], min(cost[1], cost[2]));
    }
    return 0;
}