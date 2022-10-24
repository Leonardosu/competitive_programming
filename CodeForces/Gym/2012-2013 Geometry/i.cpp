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

int cmpD(double x, double y=0, double tol = EPS) { return (x <= y+tol) ? (x+tol < y) ? -1 : 0 : 1; }
struct pt{
	double x, y;
	pt(double x=0, double y=0): x(x), y(y) {}
	pt operator +(pt p) { return pt(x+p.x, y+p.y); }
	pt operator -(pt p) { return pt(x-p.x, y-p.y); }
	pt operator *(double c) { return pt(x*c, y*c); }
	double operator *(pt p) { return x*p.x + y*p.y; }
	double operator %(pt p) { return x*p.y - y*p.x; }
    int cmp(pt p) const { 
        int t = cmpD(x, p.x);
        return t ? t : cmpD(y, p.y);
    }
    bool operator <(const pt &p)const { return cmp(p) < 0; }
	bool operator <=(const pt &p)const { return cmp(p) <= 0; }
	ll prod(pt p, pt q) { return cmpD((*this-p) % (q-p)); }
	bool between(pt p, pt q) { return prod(p, q) == 0 && min(p, q) <= *this && *this <= max(p, q); }
};

pt project(pt a, pt b) { return b * ((a*b) / (b*b)); }
double abs(pt p, pt q = pt()) { return hypot(p.x-q.x, p.y-q.y); }
ll absLL(pt p, pt q) {return (p.x - q.x)*(p.x - q.x) + (p.y - q.y)*(p.y - q.y);}
long double dist_pt_seg(pt p, pt a, pt b) {
    pt pp = a + project(p-a, b-a);
    // cout<<pp.x<<" : "<<pp.y<<"\n";
    if(pp.between(a, b)) return abs(p, pp);
    return sqrt(min(absLL(p, a), absLL(p, b)));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifdef ONLINE_JUDGE
    freopen("distance4.in", "r", stdin);
    freopen("distance4.out", "w", stdout);
#endif

    pt k, a, b;
    cin>>k.x>>k.y>>a.x>>a.y>>b.x>>b.y;
    cout<<fixed<<setprecision(10);
    cout<<dist_pt_seg(k, a, b)<<"\n";
}