//============================================================================
// Problem  : ABC 46 A - AtCoDeer and Paint Cans
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a,b,c;
    while(cin >> a >> b >> c) {
        set<int> st;
        st.insert(a); st.insert(b); st.insert(c);
        cout << st.size() << '\n';
    }
    return 0;
}