#include "bits/stdc++.h"
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct pt {
    using P = pt;
    using T = long long;

    T x, y;
    explicit pt(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
    bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P &a, P &b) const { return (a-*this).cross(b-*this); }
    T dist2() const { return x*x + y*y; }
    double dist() const { return sqrt((double)dist2()); }
    double angle() const { return atan2(y, x); }
    P unit() const { return *this/dist(); } // makes dist()=1
    P perp() const { return P(-y, x); } // rotates +90 degrees
    P normal() const { return perp().unit(); }  
};
bool onSegment(pt &s, pt &e, pt &p) {
    return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}
int sgn(ll x) { return (x > 0) - (x < 0); }

vector<pt> convexHull(vector<pt> &pts) {
    if (sz(pts) <= 1) return pts;
    sort(all(pts));
    vector<pt> h(sz(pts)+1);
    int s = 0, t = 0;
    for (int it = 2; it--; s = --t, reverse(all(pts)))
        for (pt p : pts) {
            while (t >= s + 2 && h[t-2].cross(h[t-1], p) < 0) t--;
            h[t++] = p;
        }
    return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin>>n;
    vector<pt> polygon(n);
    for(auto &p : polygon) 
    	cin>>p.x>>p.y;

    vector<pt> res = convexHull(polygon);

    cout<<sz(res)<<"\n";
    for(auto p : res) {
    	cout<<p.x<<" "<<p.y<<"\n";
    }
}