//============================================================================
// Problem  : 975E -  Hag's Khashba
// Category : Geometry (Centroid of polygon)
//============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long double T; 

struct point {
    T x,y;
    point operator + (const point &q) const { return {x+q.x, y+q.y}; }
    point operator - (const point &q) const { return {x-q.x, y-q.y}; }
    point operator + (T s) const { return {x+s, y+s}; }
    point operator - (T s) const { return {x-s, y-s}; }
    point operator * (T s) const { return {x*s, y*s}; }
    point operator / (T s) const { return {x/s, y/s}; }
    point operator - () const { return {-x, -y}; }
    T operator * (const point &q) const { return x*q.x + y*q.y; } // dot 
    T operator % (const point &q) const { return x*q.y - y*q.x; } // cross 
    T len2() const { return x*x + y*y; } // length^2
    double operator ! () const { return sqrt(len2()); } // length
    double dis(const point &q) const { return hypot(x-q.x, y-q.y); } // distance
    point rot90() const { return {-y, x}; } // rotates 90 degrees (ccw)
    point operator[] (T a) const { return {x*cos(a) - y*sin(a), x*sin(a) + y*cos(a)}; } // rotates a degrees (ccw)
    double operator ^ (const point &q) const { return atan2(*this%q, *this*q); }     // directed angle (can be -tive)
    double operator & (const point &q) const { return acos(*this*q / !*this / !q); } // smallest angle (always +tive)
    double operator > (const point &q) const { return ((*this*q)/(q*q)); } // projection on q
};

point operator * (T s, point a) { return a*s; } 

double signed_area(const vector<point> &p)
{
    double ans = 0;
    int n = (int)p.size();
    for(int i = 0; i < n; i++)
        ans += p[i] % p[(i+1) % n];
    return ans / 2.0;
}

point centroid(const vector<point> &p) 
{
    point ans = {0, 0};
    int n = (int)p.size();
    for(int i = 0; i < n; i++)
        ans = ans + (p[i] + p[(i+1) % n]) * (p[i] % p[(i+1) % n]);
    return ans / (6 * signed_area(p));
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,q,x,y,opc;
    vector<point> v;
    while(cin >> n >> q)
    {
        v = vector<point>(n);
        for(int i = 0; i < n; i++)
            cin >> v[i].x >> v[i].y;
        point first = v[0];
        for(int i = 0; i < n; i++)
            v[i] = v[i] - first;
        int a = 0, b = 1;
        point c = centroid(v), o = c;
        double ang = 0;
        while(q--)
        {
            cin >> opc;
            if(opc == 1)
            {
                cin >> x >> y; x--; y--; 
                if(x == a) swap(a,b);
                // a is the remaining pivot
                point p = c + (v[a] - o)[ang]; // real pos of point a
                point s = {p.x, p.y - !(v[a] - o)}; // new centroid 
                ang += (c-p)^(s-p); // angle between old centroid, pivot and new centroid
                c = s; // update centroid
                b = y; // update pivots
            }
            else
            {
                cin >> x; x--;
                point ans = c + (v[x] - o)[ang];
                ans = ans + first;
                cout << fixed << setprecision(10) << ans.x << " " << ans.y << '\n';
            }
        }
    }
    return 0;
}