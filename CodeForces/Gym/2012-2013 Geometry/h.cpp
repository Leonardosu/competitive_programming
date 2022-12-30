#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
#define EPS 1e-7
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

ld dist_pt_seg(pt p, pt a, pt b) {  
    pt AB = b - a;
    if(equals(a.x, b.x) && equals(a.y, b.y)) return dist(p, a);
    if (dot(p-a, AB) <= 0) return dist(p, a);
    return abs(cross(p-a, AB)) / AB.norm();
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifdef ONLINE_JUDGE
    freopen("distance3.in", "r", stdin);
    freopen("distance3.out", "w", stdout);
#endif

    pt k, a, b;
    cin>>k.x>>k.y>>a.x>>a.y>>b.x>>b.y;


    cout<<fixed<<setprecision(16);
    cout<<dist_pt_seg(k, a, b)<<"\n";
}