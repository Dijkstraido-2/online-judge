//============================================================================
// Problem  : ABC 45 B - Card Game for Three (ABC Edit)
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s[3];
    while(cin >> s[0] >> s[1] >> s[2]) {
        int n[3] = {(int)s[0].size(), (int)s[1].size(), (int)s[2].size()};
        int i[3] = {0, 0, 0};
        int cur = 0;
        while(i[cur] < n[cur]) {
            cur = s[cur][i[cur]++] - 'a';
        }
        cout << (char)(cur + 'A') << '\n';
    }
    return 0;
}