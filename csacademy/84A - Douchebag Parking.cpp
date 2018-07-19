//============================================================================
// Problem  : 84A - Douchebag Parking
// Category : Brute force
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,w,l[305],f[305];
    cin >> n >> w;
    for(int i = 0; i < n; i++)
        cin >> f[i] >> l[i];
    for(int i = 0; i < n; i++)
    {
        int s = 0;
        for(int j = i; f[j] && j < n; j++)
            s += l[j];
        if(s >= w)
        {
            cout << i+1 << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}