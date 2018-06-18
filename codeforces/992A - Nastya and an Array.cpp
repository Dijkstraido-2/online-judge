//============================================================================
// Problem  : 992A - Nastya and an Array
// Category : Sets
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    set<int> st;
    while(cin >> n)
    {
        st.clear();
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            if(x != 0)
                st.insert(x);
        }
        cout << st.size() << '\n';
    }
    return 0;
}
