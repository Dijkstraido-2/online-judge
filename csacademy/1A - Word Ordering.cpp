//============================================================================
// Problem  : 1A - Word Ordering
// Category : Sorting
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int cost[255];

inline bool cmp(const string &a, const string &b) {
    int n = a.size(), m = b.size();
    for(int i = 0; i < min(n,m); i++) {
        if(cost[a[i]] != cost[b[i]]) {
            return cost[a[i]] < cost[b[i]];
        }
    }
    return n < m;
}

vector<string> v;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    for(int i = 0; i < 26; i++) {
        cost[s[i]] = i; 
        cost[s[i]-'a'+'A'] = i+26;
    }
    int n; cin >> n;
    v = vector<string>(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), cmp);
    for(auto s : v) {
        cout << s << '\n';
    }
    return 0;
}