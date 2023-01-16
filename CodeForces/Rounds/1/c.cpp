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

const double PI = acos(-1);
const double EPS = 1e-5;
typedef long double ld;
typedef ld ptType;

int cmpD(double x, double y=0, double tol = EPS) { return (x <= y+tol) ? (x+tol < y) ? -1 : 0 : 1; }
struct pt {
    ptType x, y;
    pt(ptType x=0, ptType y=0): x(x), y(y) {}
    pt operator +(pt p) { return pt(x+p.x, y+p.y); }
    pt operator -(pt p) { return pt(x-p.x, y-p.y); }
    pt operator *(ptType c) { return pt(x*c, y*c); }
    pt operator /(ptType c) { return pt(x/c, y/c); }
    ptType operator *(pt p) { return x*p.x + y*p.y; }
    ptType operator %(pt p) { return x*p.y - y*p.x; }
    bool operator <(const pt &p)const { return cmp(p) < 0; }
    int cmp(pt p) const { 
        int t = cmpD(x, p.x);
        return t ? t : cmpD(y, p.y);
    }
    bool operator ==(pt p) { return cmp(p) == 0; }
    void read() {cin>>x>>y;}
    friend ostream& operator <<(ostream& o, pt p) { return o << "(" << p.x << "," << p.y << ")"; }
};

double abs(pt p, pt q = pt()) { return hypot(p.x-q.x, p.y-q.y); }
bool in_circle(pt &p, pt &o, double r) { return cmpD(abs(o, p), r) == 0; }
pt circumcenter(pt &p, pt &q, pt &r) {
    pt a=p-r, b=q-r, c=pt(a*(p+r)/2, b*(q+r)/2);
    return pt(c % pt(a.y, b.y), pt(a.x, b.x) % c) / (a % b);
}

pt rotate(pt a, double teta, pt o=pt()) {
	a = a - o;
	pt cis(cos(teta), sin(teta));
	return o + pt(a.x*cis.x - a.y*cis.y, a.x*cis.y + a.y*cis.x);
}

ld poly_area(vector<pt> T) {
    ld s = 0; int n = T.size();
    for(int i=0;i<n;++i) s += T[i] % T[(i+1)%n];
    return s/2.0;
}

pair<bool, ld> valid(int n, pt center, ld radius, vector<pt> &pts) {
	pair<bool, ld> ans = {false, 0};

	pt pivot = pts[0];
	ld angle = (ld) 360.0 / n;	
	angle = angle * PI / 180.0;	
	ld curr = 0;
	int qnt = 0;

	vector<pt> polygon;

	for(int i=0;i<n;++i) {
		pt p = rotate(pivot, curr, center);
		if(!in_circle(p, center, radius)) {
			return ans;
		}

		bool flag = false;
		for(auto &other : pts)
			if(p == other) {
				flag = true;
			}

		if(flag)
			qnt++;
		curr += angle;
		polygon.pb(p);
	}

	if(qnt == 3) {		
		ans = {true, poly_area(polygon)};
	}
	return ans;
}

pair<bool, ld> trivial(vector<pt> pts) {
	do {
		ld d1 = abs(pts[0], pts[1]);
		ld d2 = abs(pts[0], pts[2]);
		ld d3 = abs(pts[1], pts[2]);
		if(cmpD(d1, d2) == 0 && cmpD(d1, d3) == 0 && cmpD(d1, d2) == 0) {
			return {true, poly_area(pts)};
		}
	}while(next_permutation(ALL(pts)));

	return {false, 0};
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<pt> pts(3);
    for(auto &p : pts)
    	p.read();

    sort(ALL(pts));
    auto res = trivial(pts);
	cout<<fixed<<setprecision(12);

    if(res.f) {
    	cout<<res.s<<"\n";
    	return 0;
    }
    
    pt center = circumcenter(pts[0], pts[1], pts[2]);
    ld radius = (center.x - pts[0].x) * (center.x - pts[0].x) + (center.y - pts[0].y) * (center.y - pts[0].y);
    radius = sqrt(radius);

    ld ans = DBL_MAX;
	for(int i=3;i<=100;++i) {
		auto res = valid(i, center, radius, pts);
		if(res.f) {
			ans = min(ans, res.s);
		}
	}

	cout<<ans<<"\n";
}