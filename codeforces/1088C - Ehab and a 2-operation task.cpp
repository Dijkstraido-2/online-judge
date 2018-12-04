//============================================================================
// Problem  : 1088C - Ehab and a 2-operation task
// Category : Greedy
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin >> n) {
        vi v = vi(n); 
        for(int i = 0; i < n; i++)
            cin >> v[i];
        cout << n+1 << '\n';
        cout << 1 << " " << n << " " << 500000 << '\n';
        for(int i = 0; i < n; i++) 
            cout << 2 << " " << i+1 << " " << (500000+v[i]-i) << '\n';
    }
    return 0;
}