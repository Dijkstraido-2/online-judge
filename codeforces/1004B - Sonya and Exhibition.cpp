//============================================================================
// Problem  : 1004B - Sonya and Exhibition
// Category : Simple Math
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int n,m;
int l[1005],r[1005];
string ans;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> m)
    {
        for(int i = 0; i < m; i++)
            cin >> l[i] >> r[i];
        int mx = -1;
        for(int k = 0; k < 2; k++)
        {
            string s;
            for(int i = 0, j = k; i < n; i++, j=1-j)
                s.push_back('0'+j);
            int sum = 0;
            for(int i = 0; i < m; i++)
            {
                int f[2] = {0, 0}; 
                for(int j = l[i]-1; j <= r[i]-1; j++)
                    f[(s[j] == '1')]++;
                sum += f[0]*f[1];
            }
            if(sum > mx)
            {
                mx = sum;
                ans = s;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}