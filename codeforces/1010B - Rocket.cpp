//============================================================================
// Problem  : 1010B - Rocket
// Category : Binary Search
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(0);
    int m,n,x,d[30];
    cin >> m >> n;
    for(int i = 0; i < n; i++)
    {
        cout << 1 << '\n'; cout.flush();
        cin >> d[i];
        if(!d[i])
            return 0;
    }
    int lo = 1, hi = m, mid, k = 0;
    while(lo <= hi) 
    {
        mid = lo + (hi-lo)/2;
        cout << mid << '\n'; cout.flush();
        cin >> x;
        x *= d[k++]; 
        if(k == n)
            k = 0;
        if(x == 0) 
            return 0;
        else if(x < 0)
            hi = mid-1;
        else
            lo = mid+1;
    }
    return 0;
}