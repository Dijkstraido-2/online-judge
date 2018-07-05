//============================================================================
// Problem  : 1000A - Codehorses T-shirts
// Category : Greedy
//============================================================================
#include <bits/stdc++.h>
using namespace std;

string v[9] = {"M", "S", "L", "XS", "XL", "XXS", "XXL", "XXXS", "XXXL"};

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,ans;
    string s;
    map<string,int> a,b;
    while(cin >> n)
    {
        a.clear();
        for(int i = 0; i < n; i++) { cin >> s; a[s]++; }
        b.clear();
        for(int i = 0; i < n; i++) { cin >> s; b[s]++; }
        ans = 0;
        for(int i = 0; i < 9; i++)
            ans += abs(a[v[i]]-b[v[i]]);
        cout << ans/2 << '\n';
    }
    return 0;
}