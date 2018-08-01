//============================================================================
// Problem  : 916B - Jamie and Binary Sequence
// Category : Greedy
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 200070;
ll n,k,t;
ll f[MAX];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int offset = MAX - 70;
    while(cin >> n >> k)
    {
        memset(f, 0, sizeof f); t = 0;
        for(int i = 0; i <= 60; i++)
            if(n & (1LL << i))
            {
                f[i+offset] = 1;
                t++;
            }
        if(k < t) 
            cout << "No" << '\n';
        else
        {
            for(int i = MAX - 1; i >= 1 && t + f[i] <= k; i--)
            {
                t += f[i];
                f[i-1] += f[i] * 2;
                f[i] = 0;
            }
            if(t < k)
            {
                int j = 0;
                while(f[j] == 0)
                    j++;
                for(int i = j; i > 0 && t < k; i--, t++)
                {
                    f[i]--;
                    f[i-1] += 2;
                }
            }
            cout << "Yes" << '\n';
            for(int i = MAX - 1; i >= 0; i--)
                while(f[i]--)
                    cout << " " << i-offset;
            cout << '\n';
        }
    }
    return 0;
}