//============================================================================
// Problem  : AGC 5 A - STring
// Category : Stack
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s;
    while(cin >> s) {
        stack<char> st;
        for(auto c : s) {
            if(st.empty() || c == 'S' || (c == 'T' && st.top() == 'T')) {
                st.push(c);
            } else {
                st.pop();
            }
        }
        cout << st.size() << '\n';
    }
    return 0;
}