//============================================================================
// Problem  : 1082D - Maximum Diameter Graph
// Category : Constructive Algorithms
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,ones,ans,first,last;
    vi v;
    vii edges;
    while(cin >> n) {
        v = vi(n); ones = 0;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            if(v[i] == 1) {
                ones++;
                v[i] *= -1;
            }
        }
        ans = n-ones; first = last = -1; edges.clear();
        for(int i = 0; i < n; i++)
            if(v[i] > 1) {
                if(last != -1) {
                    v[last]--; v[i]--;
                    edges.push_back({last,i});
                }
                last = i;
                if(first == -1)
                    first = i;
            }
        int addFirst = 0, addLast = 0, flag = 0, ok = 1;
        for(int i = 0; i < n; i++)
            if(v[i] == -1) {
                int found = 0;
                if(flag) {
                    for(int j = 0; j < n && !found; j++)
                        if(v[j] > 0) {
                            v[j]--;
                            edges.push_back({i,j});
                            found = 1;
                            if(j == first && !addFirst) {
                                ans++;
                                addFirst = 1;
                            }
                        }
                } else {
                    for(int j = n-1; j >= 0 && !found; j--)
                        if(v[j] > 0) {
                            v[j]--;
                            edges.push_back({i,j});
                            found = 1;
                            if(j == last && !addLast) {
                                ans++;
                                addLast = 1;
                            }
                        }
                }
                flag = !flag;
                if(!found) 
                    ok = 0;
            }
        if(!ok) {
            cout << "NO" << '\n';
        } else {
            cout << "YES " << ans-1 << '\n';
            cout << edges.size() << '\n';
            for(auto p : edges) 
                cout << p.first+1 << " " << p.second+1 << '\n';
        }
    }
    return 0;
}