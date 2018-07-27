//============================================================================
// Problem  : 1010A - Fly
// Category : Binary Search
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int k;
double m,p[2005],a[1005],b[1005];

int can(double f) 
{
    for(int i = 0; i < k; i++)
    {
        double need = (m + f) / p[i];
        if(need > f)
            return 0;
        f -= need; 
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin >> n >> m) 
    {
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++)
            cin >> b[i];
        k = 1; p[0] = b[0];
        for(int i = 1; i < n; i++)
        {
            p[k++] = a[i];
            p[k++] = b[i]; 
        }
        p[k++] = a[0];
        // binary search
        double lo = 0, hi = 2000000000, ans = -1;
        for(int it = 0; it < 60; it++)
        {
            double mid = (lo+hi)/2;
            if(can(mid)) 
            {
                ans = mid;
                hi = mid;
            }
            else
                lo = mid;
        }
        if(ans < 0)
            cout << "-1" << '\n';
        else
            cout << fixed << setprecision(9) << ans << '\n';
    }
    return 0;
}