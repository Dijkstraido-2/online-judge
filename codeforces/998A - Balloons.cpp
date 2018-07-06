//============================================================================
// Problem  : 998A - Balloons
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int n,v[12];

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n)
    {
        for(int i = 0; i < n; i++)
        cin >> v[i];
        int finish = 0;
        for(int i = 0; i < n && !finish; i++)
        {
            int s = 0;
            for(int j = 0; j < n; j++)
                if(i != j)
                    s += v[j];
            if(s > 0 && s != v[i])
            {
                cout << 1 << '\n' << i+1 << '\n';
                finish = 1;
            }
        }
        if(!finish) cout << -1 << '\n';
    }
    return 0;
}