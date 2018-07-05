//============================================================================
// Problem  : 995B - Suit and Tie
// Category : Greedy
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vi v;
int n;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n)
    {
        v = vi(2*n);
        for(int i = 0; i < 2*n; i++)
            cin >> v[i];
        int ans = 0;
        for(int i = 0; i < 2*n; i += 2)
            if(v[i+1] != v[i])
            {
                int pos = -1;
                for(int j = i+2; j < 2*n && pos == -1; j++)
                    if(v[j] == v[i])
                        pos = j;
                ans += pos - (i+1);
                for(int j = pos; j >= i+2; j--)
                    swap(v[j], v[j-1]);
            }
        cout << ans << '\n';
    }
    return 0;
}