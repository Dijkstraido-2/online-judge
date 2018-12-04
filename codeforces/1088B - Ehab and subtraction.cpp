//============================================================================
// Problem  : 1088B - Ehab and subtraction
// Category : Sorting
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,k;
    while(cin >> n >> k) {
        vi v = vi(n);
        for(int i = 0; i < n; i++) 
            cin >> v[i];
        sort(v.begin(), v.end());
        ll sum = 0;
        for(int i = 0, pos = 0; i < k; i++, pos++) {
            while(pos < n && v[pos]-sum <= 0)
                pos++;
            cout << (pos >= n? 0 : v[pos]-sum) << '\n';
            sum += (pos >= n? 0 : v[pos]-sum);
        }
    }
    return 0;
}