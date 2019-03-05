//============================================================================
// Problem  : ABC 43 B - Unhappy Hacking (ABC Edit)
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s,t;
    while(cin >> s) {
        t = "";
        for(auto c : s) {
            if(c == '0' || c == '1')
                t.push_back(c);
            else if(!t.empty())
                t.pop_back();
        }
        cout << t << '\n';
    }
    return 0;
}