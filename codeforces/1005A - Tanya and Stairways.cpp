//============================================================================
// Problem  : 1005A - Tanya and Stairways
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,pre,cur;
    vector<int> v;
    while(cin >> n)
    {
        cin >> pre; v.clear();
        for(int i = 1; i < n; i++)
        {
            cin >> cur;
            if(cur == 1)
                v.push_back(pre);
            pre = cur;
        }
        v.push_back(pre);
        cout << v.size() << '\n';
        for(int x : v)
            cout << x << " ";
        cout << '\n';
    }
    return 0;
}