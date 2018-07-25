//============================================================================
// Problem  : 74B - Subway Ride
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll M[305][305],des[305],sum,ans;
int n;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n)
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> M[i][j];
        ans = 0;
        for(int k = 0; k < 2*n; k++)
        {
            int cur = k % n;
            des[cur] = sum = 0;
            for(int i = 0; i < n; i++)
            {
                des[i] += M[cur][i];
                sum += des[i];
            }
            ans = max(ans, sum);
        }
        cout << ans << '\n';
    }
    return 0;
}