//============================================================================
// Problem  : AGC 3 A - Wanna go back home
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s;
    while(cin >> s) {
        int N = 0, S = 0, E = 0, W = 0;
        for(auto c : s) {
            if(c == 'N') {
                N = 1;
            } else if(c == 'S') {
                S = 1;
            } else if(c == 'W') {
                W = 1;
            } else if(c == 'E') {
                E = 1;
            }
        }
        cout << (N != S || E != W? "No" : "Yes") << '\n';
    }
    return 0;
}