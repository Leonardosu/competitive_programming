#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
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

int inPolygon(vector<pt> &p, pt a) {
    int cnt = 0, n = sz(p);
    for(int i=0;i<n;++i) {
        pt q = p[(i + 1) % n];
        if (onSegment(p[i], q, a)) {
            return -1;
        }
        cnt ^= ((a.y<p[i].y) - (a.y<q.y)) * a.cross(p[i], q) > 0;
    }    
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin>>n>>m;
    vector<pt> polygon(n);
    for(auto &q : polygon)
    	cin>>q.x>>q.y;

    while(m--) {
    	pt now;
    	cin>>now.x>>now.y;

    	int state = inPolygon(polygon, now);

    	if(state == -1) {
    		cout<<"BOUNDARY";
    	} else if(state == 0) {
    		cout<<"OUTSIDE";
    	} else {
    		cout<<"INSIDE";
    	}
        cout<<"\n";
    }
}