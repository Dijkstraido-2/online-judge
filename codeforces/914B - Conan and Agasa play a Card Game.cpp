//============================================================================
// Problem  : 914B - Conan and Agasa play a Card Game
// Category : Games + Greedy
//============================================================================
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;
int f[MAX],n;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int x;
    while(cin >> n)
    {
        memset(f, 0, sizeof f);
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            f[x]++;
        }
        bool win = false;
        for(int i = MAX - 1; i >= 1 && !win; i--)
            if(f[i] % 2 != 0)
                win = true;
        cout << (win? "Conan" : "Agasa") << '\n';
    }
    return 0;
}