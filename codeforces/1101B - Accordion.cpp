//============================================================================
// Problem  : 1101B - Accordion
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s;
    while(cin >> s) {
        int n = s.size(), l = n, r = -1, cont = 0; 
        for(int i = 0; i < n; i++) {
            if(cont == 0 && s[i] == '[')
                cont++;
            else if(cont == 1 && s[i] == ':') {
                cont++;
                l = i;
            }
        }
        cont = 0;
        for(int i = n-1; i >= 0; i--) {
            if(cont == 0 && s[i] == ']')
                cont++;
            else if(cont == 1 && s[i] == ':') {
                cont++;
                r = i;
            }
        }
        int mid = 0;
        for(int i = l+1; i < r; i++) {
            mid += (s[i] == '|');
        }
        cout << (l >= r? -1 : 4+mid) << '\n';
    }
    return 0;
}