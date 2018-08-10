//============================================================================
// Judge    : 918A - Eleven
// Category : Basic Programming
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int isFib[1005];

void init()
{
    int a = 1, b = 1, c = 2;
    isFib[1] = 1;
    while(c <= 1000)
    {
        isFib[c] = 1;
        a = b;
        b = c;
        c = a + b;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    init();
    int n;
    while(cin >> n)
    {
        for(int i = 1; i <= n; i++)
            cout << (isFib[i]? "O" : "o");
        cout << '\n';
    }
    return 0;
} 