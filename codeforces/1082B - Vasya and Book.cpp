//============================================================================
// Problem  : 1082B - Vasya and Book
// Category : Greedy
//============================================================================
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s;
    vector<int> v;
    int n,ans;
    while(cin >> n >> s) {
        v.clear();
        for(int i = 0; i < n; i++) {
            int nxt = i;
            while(nxt < n && s[nxt] == s[i])
                nxt++;
            int cont = nxt-i;
            v.push_back((s[i]=='S'? -1:1) * cont);
            i = nxt-1;
        }
        n = v.size(); ans = 0;
        for(int i = 0; i < n; i++)
            if(v[i] > 0) {
                ans = max(ans, v[i]);
                int add = (v[0] < 0)? (n>3) : (n>2);
                if(add) 
                    ans = max(ans, v[i]+1);
                if(i+2 < n && v[i+1] == -1) {
                    ans = max(ans, v[i]+v[i+2]);
                    int can = (v[0] < 0)? (n>5) : (n>4);
                    if(can) 
                        ans = max(ans, v[i]+v[i+2]+1);
                }
            }
        cout << ans << '\n';
    }
    return 0;
}