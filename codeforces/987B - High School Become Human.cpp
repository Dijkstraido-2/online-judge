//============================================================================
// Problem  : 987B - High School Become Human
// Category : Math
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double EPS = 1e-08;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll x,y;
    while(cin >> x >> y)
    {
        double a = y * log(x), b = x * log(y);
        if(x == y || fabs(a-b) < EPS)
            cout << "=" << '\n';
        else if(a < b)
            cout << "<" << '\n';
        else
            cout << ">" << '\n';
    }
    return 0;
}