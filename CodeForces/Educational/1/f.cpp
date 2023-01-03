#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

const double EPS = 1e-6;
const double PI = acos(-1);

struct pt {
    ld x, y;
    pt(ld x=0, ld y=0): x(x), y(y) {}

    pt operator +(pt p) { return pt(x+p.x, y+p.y); }
    pt operator -(pt p) { return pt(x-p.x, y-p.y); }
};

ld dot(pt v1, pt v2) {
    return v1.x*v2.x + v1.y*v2.y;
}
ld cross(pt v1, pt v2) {
    return v1.x*v2.y - v1.y*v2.x;
}

ld len(pt a, pt b, pt p1, pt p2) {
    pt AB = b - a;
    pt P1P2 = p2 - p1;

    return cross(p1 - a, P1P2) / cross(AB, P1P2);
    // (AP.x*PPq.y - PPq.x*AP.y)
    // /((AB.x*PPq.y-PPq.x*AB.y);
}
int dir(pt v1, pt v2) {
    ld result = cross(v1, v2);
    if(result > EPS) return 1;
    else if(result < -EPS) return -1;
    return 0;
}

vector<pt> polygon;
pt pivot;

bool cmp(pt &a, pt& b) {
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin>>n>>m;

    polygon.resize(n);
    for(auto &p : polygon)
        cin>>p.x>>p.y;
    polygon.pb(polygon[0]);

    cout<<fixed<<setprecision(12);
    while(m--) {
        pt a,b;
        cin>>a.x>>a.y>>b.x>>b.y;
        pt AB = b - a;

        vector<pair<ld,int>> inter;
        for(int i=0;i<n;++i) {
            pt AB = b - a;
            int dir1 = dir(polygon[i]-a, AB);
            int dir2 = dir(polygon[i+1]-a, AB);
            if(dir1 != dir2) {
                inter.pb({len(a, b, polygon[i], polygon[i+1]), dir1-dir2});
            }
        }

        sort(ALL(inter));
        ld totalLen = 0;
        int sinal = 0;
        for(int i=0;i+1<(int)inter.size();++i) {
            ld tam = inter[i].f;
            sinal += inter[i].s;

            if(sinal)
                totalLen += inter[i+1].f - tam;
        }
        

        cout<<fixed<<setprecision(12);
        cout<<totalLen * sqrt(AB.x*AB.x + AB.y*AB.y)<<"\n";
    }
}
