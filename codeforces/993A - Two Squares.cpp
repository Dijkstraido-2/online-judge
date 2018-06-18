//============================================================================
// Problem  : 993A - Two Squares
// Category : Geometry
//============================================================================
#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-7; 
const double PI = 2*acos(0.0); 

typedef double T; // coordinate type 

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
    point operator[] (double a) const { // rotates by 'a' radians (ccw) 
        return {x*cos(a) - y*sin(a), x*sin(a) + y*cos(a)}; 
    } 
};
point operator * (T s, point a) { return a*s; } 

typedef vector<point> vp;
vp p(8);

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    double mn_x, mn_y, mx_x, mx_y, cx, cy;
    int intersect;
    while(cin >> p[0].x >> p[0].y)
    {
        for(int i = 1; i < 8; i++)
            cin >> p[i].x >> p[i].y;
        intersect = 0; 
        for(int k = 0; k < 2; k++) 
        {
            // Get bounding coordinates of the "regular" square
            mn_x = mn_y = 200; mx_x = mx_y = -200;
            for(int i = (!k? 0:4); i < (!k? 4:8); i++)
            {
                mn_x = min(mn_x, p[i].x); mn_y = min(mn_y, p[i].y);
                mx_x = max(mx_x, p[i].x); mx_y = max(mx_y, p[i].y);
            }
            // Check if any corner of the rotated square is inside the regular square
            for(int i = (!k? 4:0); i < (!k? 8:4); i++)
                if(mn_x <= p[i].x && p[i].x <= mx_x && mn_y <= p[i].y && p[i].y <= mx_y)
                    intersect = 1;
            // Check if the center of the rotated square is inside the regular square
            cx = cy = 0;
            for(int i = (!k? 4:0); i < (!k? 8:4); i++)
                cx += p[i].x, cy += p[i].y;
            cx /= 4; cy /= 4;
            if(mn_x <= cx && cx <= mx_x && mn_y <= cy && cy <= mx_y)
                intersect = 1;
            // Rotate the squares so that we can try again
            int id = 4; double mn = p[4].y; 
            for(int i = 5; i < 8; i++)
                if(p[i].y < mn)
                {
                    mn = p[i].y;
                    id = i;
                }
            for(int i = 0; i < 8; i++)
               p[i] = (p[i] - p[id])[PI/4] + p[id];
        }
        cout << (intersect? "YES" : "NO") << '\n';
    } 
    return 0;
}
