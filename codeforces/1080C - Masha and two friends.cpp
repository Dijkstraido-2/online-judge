//============================================================================
// Problem  : 1080C - Masha and two friends
// Category : Implementation
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;

ii count(ll r, ll c, bool rev) { // (white, black)
    ll t = r*c;
    if(t%2 == 0)
        return {t/2, t/2};
    else if(rev)
        return {t/2, t/2+1};
    else 
        return {t/2+1, t/2};
}

bool intersect(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
    return (x1 <= x4 && x2 >= x3 && y1 <= y4 && y2 >= y3);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll q,r,c,x1,y1,x2,y2,x3,y3,x4,y4,b,w;
    cin >> q;
    while(q--) {
        cin >> r >> c;
        cin >> x1 >> y1 >> x2 >> y2; // (col, row)
        cin >> x3 >> y3 >> x4 >> y4;
        auto p = count(r,c,0);
        w = p.first; b = p.second;
        // Paint white
        auto r1 = count(y2-y1+1, x2-x1+1, (x1+y1)%2);
        w -= r1.first; b -= r1.second;
        w += (y2-y1+1)*(x2-x1+1);
        // If there is any intersection, restore first
        if(intersect(x1,y1,x2,y2,x3,y3,x4,y4)) {
            ll x5,y5,x6,y6;
            x5 = max(x1,x3); y5 = max(y1,y3);
            x6 = min(x2,x4); y6 = min(y2,y4);
            auto rr = count(y6-y5+1, x6-x5+1, (x5+y5)%2);
            w -= (y6-y5+1)*(x6-x5+1);
            w += rr.first; b += rr.second;
        }
        // Paint black
        auto r2 = count(y4-y3+1, x4-x3+1, (x3+y3)%2);
        w -= r2.first; b -= r2.second;
        b += (y4-y3+1)*(x4-x3+1);
        cout << w << " " << b << '\n';
    }
    return 0;
}