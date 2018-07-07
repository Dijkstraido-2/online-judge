//============================================================================
// Problem  : 977A - Wrong Subtraction
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,k;
    while(cin >> n >> k)
    {
        for(int i = 0; i < k; i++)
            if(n % 10 == 0)
                n /= 10;
            else
                n--;
        cout << n << '\n';
    }
    return 0;
}