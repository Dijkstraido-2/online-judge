//============================================================================
// Problem  : 1029C - Maximal Intersection
// Category : RMQ
//============================================================================
#include <bits/stdc++.h>
using namespace std;

const int MAX = 300005; 
const int INF = 1e9+5;
int t1[MAX][20]; 
int t2[MAX][20]; 
int n; 

void build()
{
    for(int k = 1; (1<<k) <= n; k++) 
        for(int i = 0; i+(1<<k)-1 < n; i++) 
        {
            t1[i][k] = max(t1[i][k-1], t1[i+(1<<(k-1))][k-1]);
            t2[i][k] = min(t2[i][k-1], t2[i+(1<<(k-1))][k-1]);
        }
}

int get_max(int l, int r)     
{
    if(r < l) return -INF;
    int k = 0;                   
    while((1<<k) <= r-l+1) k++; 
    k--;         
    return max(t1[l][k], t1[r-(1<<k)+1][k]); 
}

int get_min(int l, int r)     
{
    if(r < l) return INF;
    int k = 0;                   
    while((1<<k) <= r-l+1) k++; 
    k--;         
    return min(t2[l][k], t2[r-(1<<k)+1][k]); 
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n)
    {
        for(int i = 0; i < n; i++)
            cin >> t1[i][0] >> t2[i][0];
        build();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int l = max(get_max(0,i-1), get_max(i+1,n-1));
            int r = min(get_min(0,i-1), get_min(i+1,n-1));
            ans = max(ans, (r<l? 0 : r-l));
        }
        cout << ans << '\n';
    }    
    return 0;
}