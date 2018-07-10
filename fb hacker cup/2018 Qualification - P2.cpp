#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int ntest=1,T,n,x;
    cin >> T;
    while(T--)
    {
        cin >> n;
        for(int i = 0; i <= n; i++)
            cin >> x;
        if(n%2 != 0)
            cout << "Case #" << ntest++ << ": " << 1 << '\n' << "0.0" << '\n';
        else
            cout << "Case #" << ntest++ << ": " << 0 << '\n';
    }
    return 0;
}