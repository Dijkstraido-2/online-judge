//============================================================================
// Problem  : 994A - Fingerprints
// Category : Basic Programming
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,a[15],b[15];
    while(cin >> n >> m)
    {
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < m; i++)
            cin >> b[i];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(a[i] == b[j])
                {
                    cout << a[i] << " ";
                    break;
                }
        cout << '\n';
    }
    return 0;
}
