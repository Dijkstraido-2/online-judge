//============================================================================
// Problem  : 1078A - Barcelonian Distance
// Category : Geometry
//============================================================================
#include <bits/stdc++.h>
using namespace std;

struct point { double x,y; };
bool operator < (const point &a, const point &b) { return a.x != b.x? a.x < b.x : a.y < b.y; }

long long a,b,c; // a*x + b*y + c = 0
point p,q;
set<point> v;

void intersections() {
    double aux_x,aux_y;
    if(b != 0) {
        aux_y = (-a*p.x - c)/b;
        if(min(p.y,q.y) <= aux_y && aux_y <= max(p.y,q.y)) {
            v.insert({p.x, aux_y}); 
        } 
        aux_y = (-a*q.x - c)/b;
        if(min(p.y,q.y) <= aux_y && aux_y <= max(p.y,q.y)) {
            v.insert({q.x, aux_y});
        } 
    }
    if(a != 0) {
        aux_x = (-b*p.y - c)/a;
        if(min(p.x,q.x) <= aux_x && aux_x <= max(p.x,q.x)) {
            v.insert({aux_x, p.y});
        } 
        aux_x = (-b*q.y - c)/a;
        if(min(p.x,q.x) <= aux_x && aux_x <= max(p.x,q.x)) {
            v.insert({aux_x, q.y});
        } 
    }
}

double euclid(point a, point b) { return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)); }
double manhattan(point a, point b) { return fabs(a.x-b.x) + fabs(a.y-b.y); }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    double ans;
    while(cin >> a >> b >> c >> p.x >> p.y >> q.x >> q.y) {
        v.clear(); 
        intersections(); 
        ans = manhattan(p,q);
        if(v.size() == 2) {
            point l1 = *v.begin(), l2 = *(--v.end());
            ans = min(ans, min(manhattan(p,l1) + euclid(l1,l2) + manhattan(l2,q),
                               manhattan(p,l2) + euclid(l2,l1) + manhattan(l1,q)));
        }
        cout << fixed << setprecision(10) << ans << '\n';
    }    
    return 0;
}