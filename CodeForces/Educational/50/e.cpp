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

typedef long double ld;
const double EPS = 1e-6;
struct pt {
	ll x, y;
	pt(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {}
	pt operator +(pt p) { return pt(x+p.x, y+p.y); }
	pt operator -(pt p) { return pt(x-p.x, y-p.y); }
	pt operator * (ll c) { return pt(x * c, y * c); }

	bool operator<(const pt &p)const { return x == p.x ? y < p.y : x < p.x; }
	bool operator ==(const pt &p) const { return x == p.x && y == p.y; }
};

ll dot(pt v1, pt v2) { return v1.x*v2.x + v1.y*v2.y;}
ll cross(pt v1, pt v2) { return v1.x*v2.y - v1.y*v2.x;}

struct Segment {
    pt p1, p2;
    ll a, b, c;
    Segment(pt ini = pt(), pt fim = pt()) {
        p1 = ini, p2 = fim;
        a = -(ini.y - fim.y);
        b = ini.x - fim.x;
        c = a * fim.x + b * fim.y;
    }

    bool inLine(pt p) { return cross(p-p1, p2-p1) == 0;}
    bool inSegment(pt p) {
        return inLine(p) && dot(p1 - p2, p - p2) >= 0 && dot(p2 - p1, p - p1) >= 0;
    }

    pt lineIntersection(Segment other) {
        ld x = c * other.b - b * other.c;
        ld y = a * other.c - c * other.a;
        ld tmp = a * other.b - b * other.a;
        return pt(round(x/tmp), round(y/tmp));
    }
    
};

ll gcd (ll a, ll b) { while (b) { a %= b,swap(a, b);}return a;}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    vector<Segment> segs(n);

    for(auto &seg : segs) {
        pt ini, fim;
        cin>>ini.x>>ini.y>>fim.x>>fim.y;
        seg = Segment(ini, fim);
    }

    ll ans = 0;
    for(int i=0;i<n;++i) {
    	auto seg1 = segs[i];
        set<pt> invalidos;

    	for(int j=0;j<i;++j) {
    		auto seg2 = segs[j];
            pt mid = seg1.lineIntersection(seg2);
    		if(seg1.inSegment(mid) && seg2.inSegment(mid)) { 
                invalidos.insert(mid);
    		}
    	}

        pt v = seg1.p2 - seg1.p1;
        ans += gcd(abs(v.x), abs(v.y)) - invalidos.size() + 1;
    }

    cout<<ans<<"\n";
}