#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
#define EPS 1e-6
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

struct pt{
	ld x, y;
	pt(ld x=0, ld y=0): x(x), y(y) {}
	pt operator +(pt p) { return pt(x+p.x, y+p.y); }
	pt operator -(pt p) { return pt(x-p.x, y-p.y); }
    ld norm() {return sqrt(x*x + y*y);}
};

ld dist(pt a, pt b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
ld dot(pt v1, pt v2) {
    return v1.x*v2.x + v1.y*v2.y;
}
ld cross(pt v1, pt v2) {
    return v1.x*v2.y - v1.y*v2.x;
}
bool equals(ld x, ld y) {
    return fabs(x-y) < EPS;
}
bool between(ld left, ld mid, ld right) { // left < mid < right
    return (left < mid && mid < right);
}

bool intersect(pt a, pt b, pt c, pt d) {
    // line: A + (B-A)*t, line1 intersect line <=> 0 < t1 < 1 && 0 < t2 < 1
    pt v1 = b - a;
    pt v2 = d - c;

    ld det = cross(v1, v2);
    if (equals(det, 0)) return false;

    pt v3 = d - a;
    ld t = cross(v3, v2) / det;    
    ld u = cross(v1, v3) / det;
    return between(0, t, 1) && between(0, u, 1);
}

long double dist_pt_seg(pt p, pt a, pt b) {
    pt AB = b - a;
    if(equals(a.x, b.x) && equals(a.y, b.y)) return dist(p, a);
    if (dot(p-a, AB) <= 0) return dist(p, a);
    else if(dot(p-b, AB) >= 0) return dist(p, b);
    return abs(cross(p-a, AB)) / AB.norm();
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifdef ONLINE_JUDGE
    freopen("position.in", "r", stdin);
    freopen("position.out", "w", stdout);
#endif

    vector<pt> pts(4);
    for(auto &p : pts)
    	cin>>p.x>>p.y;

    long double ans = dist_pt_seg(pts[0], pts[2], pts[3]);
    if (intersect(pts[0], pts[1], pts[2], pts[3])) {
        ans = 0;
    } else {
        vector<array<pt, 3>> queries = {
        	{pts[0], pts[2], pts[3]},
        	{pts[1], pts[2], pts[3]},
        	{pts[2], pts[0], pts[1]},
        	{pts[3], pts[0], pts[1]},
        };

        for(auto query : queries) {
    		ans = min(ans, dist_pt_seg(query[0], query[1], query[2]));    
        }
    }

    cout<<fixed<<setprecision(12);
    cout<<ans<<"\n";
}