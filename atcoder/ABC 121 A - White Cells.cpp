//============================================================================
// Problem  : ABC 121 A - White Cells
// Category : Simple Math
//============================================================================
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int H,W,h,w;
    while(cin >> H >> W >> h >> w) {
        cout << H*W - H*w - h*W + w*h << '\n';
    }
    return 0;
}