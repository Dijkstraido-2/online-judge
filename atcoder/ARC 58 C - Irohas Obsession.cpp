//============================================================================
// Problem  : ARC 58 C - Irohas Obsession
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

vector<int> dislike;
int n,k;

bool ok(int x) {
    while(x > 0) {
        if(dislike[x % 10])
            return false;
        x /= 10;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> k) {
        dislike = vector<int>(10, 0);
        for(int i = 0; i < k; i++) {
            int x; cin >> x;
            dislike[x] = 1;
        }
        while(!ok(n)) {
            n++;
        }
        cout << n << '\n';
    }
    return 0;
}