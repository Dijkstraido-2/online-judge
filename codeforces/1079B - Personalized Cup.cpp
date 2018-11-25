//============================================================================
// Problem  : 1079B - Personalized Cup
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s;
    int n;
    while(cin >> s) {
        n = s.size();
        for(int r = 1; r <= 5; r++) {
            int c = n/r + (n%r? 1:0), k = n%r;
            if(c <= 20) {
                cout << r << " " << c << '\n';
                for(int i = 0, pos = 0; i < r; i++) {
                    if(k == 0 || i < k) {
                        for(int j = 0; j < c; j++)
                            cout << s[pos++];
                        cout << '\n';
                    } else {
                        for(int j = 0; j < c-1; j++)
                            cout << s[pos++];
                        cout << "*" << '\n';
                    }
                }
                break;
            }
        }
    }
    return 0;
}