//============================================================================
// Problem  : 1003B - Binary String Constructing
// Category : Constructive Algorithm
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a,b,x;
    while(cin >> a >> b >> x)
    {
        if(x % 2 == 0)
        {
            if(a > b)
            {
                for(int i = 0; i < x/2; i++)
                    cout << "01";
                for(int i = 0; i < b-x/2; i++)
                    cout << "1";
                for(int i = 0; i < a-x/2; i++)
                    cout << "0";
            }
            else
            {
                for(int i = 0; i < x/2; i++)
                    cout << "10";
                for(int i = 0; i < a-x/2; i++)
                    cout << "0";
                for(int i = 0; i < b-x/2; i++)
                    cout << "1";
            }
        }
        else
        {
            for(int i = 0; i < x/2; i++)
                cout << "01";
            for(int i = 0; i < a-(x/2); i++)
                cout << "0";
            for(int i = 0; i < b-(x/2); i++)
                cout << "1";
        }
        cout << '\n';
    }
    return 0;
}