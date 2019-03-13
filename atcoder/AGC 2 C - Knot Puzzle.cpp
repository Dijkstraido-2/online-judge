//============================================================================
// Problem  : AGC 2 C - Knot Puzzle
// Category : Brute force
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,l;
    while(cin >> n >> l) {
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int pos = -1;
        for(int i = 0; i < n-1 && pos == -1; i++) {
            if(v[i]+v[i+1] >= l) {
                pos = i;
            }
        }
        if(pos == -1) {
            cout << "Impossible" << '\n';
            continue;
        }
        cout << "Possible" << '\n';
        for(int i = 1; i <= pos; i++) {
            cout << i << '\n';
        }
        for(int i = n-1; i > pos+1; i--) {
            cout << i << '\n';
        }
        cout << pos+1 << '\n';
    }
    return 0;
}