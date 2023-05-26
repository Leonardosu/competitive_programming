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

const double EPS = 1e-7;

struct pt {
    using P = pt;
    using T = double;

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
bool on_segment(pt &s, pt &e, pt &p) {
    return p.cross(s, e) == EPS && (s - p).dot(e - p) <= EPS;
}
int sgn(double x) { return (x > 0) - (x < 0); }

bool seg_int(pt a, pt b, pt c, pt d) {
    auto oa = c.cross(d, a), ob = c.cross(d, b),
         oc = a.cross(b, c), od = a.cross(b, d);
    if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
        return true;

    bool inter = false;
    if (on_segment(c, d, a)) inter = true;
    if (on_segment(c, d, b)) inter = true;
    if (on_segment(a, b, c)) inter = true;
    if (on_segment(a, b, d)) inter = true;

    return inter;
}


using polygon = vector<pt>;
int n, altura;
vector<polygon> polygons;
const int N = 15;
double cost[N][N];

bool intersect(int i, int j, double mid) {
    auto &p1 = polygons[i];
    auto &p2 = polygons[j];
    int t1 = sz(polygons[i]), t2 = sz(polygons[j]);

    bool toca = false;
    bool azedou = false;
    i = 1, j = 0; //agr sao idx dos vertices

    while(true) {
        if(azedou) return toca;

        pt a = p1[i], b = p1[(i+1)%t1];
        pt c = p2[j], d = p2[(j+t2-1)%t2];

        if(b.y == d.y && b.y == altura) {
            azedou = true;
        }

        if(seg_int(
            a, 
            b,
            pt(c.x + mid, c.y), 
            pt(d.x + mid, d.y))) {
            toca = true;
            break;
        } else {
            if(b.y > d.y) {
                j--;
                if(j < 0) j+=t2;
            } else {
                i++;
            }
        }
    }

    return toca;    
}

double getCost(int i, int j) {
    double l = polygons[i][1].x - polygons[i][0].x, r = 2e9;
    int tentativas = 50;
    while(tentativas--) {
        double mid = (l+r)/2;
        if(!intersect(i, j, mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }  
    return r;
}

void pre_process() {
    for(int i=0;i<n;++i) { // i - j  # i na esquerda
        for(int j=0;j<n;++j) 
            if(i != j) {
                cost[i][j] = getCost(i, j);              
            }
    }
}

const int MASK = 1<<15;

bool vis[MASK][N];
double dp[MASK][N];
int base[N];

double solve(int mask, int last) {
    if(__builtin_popcount(mask) == n) {
        return base[last];
    }

    if(vis[mask][last]) return dp[mask][last];

    double ans = 1e12;
    for(int i=0;i<n;++i) {
        if((mask & (1<<i)) == 0) {
            ans = min(ans, cost[last][i] + solve(mask|(1<<i), i));
        }
    }

    vis[mask][last] = true;
    dp[mask][last] = ans;
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    double timing = clock();
    
    cin>>n;

    for(int i=0;i<n;++i) {
        int m, q, w;
        cin>>m;

        polygon p;
        base[i] = 0;
        for(int j=0;j<m;++j) {
            cin>>q>>w;

            base[i] = max(base[i], q); 
            altura = max(altura, w);
            p.pb(pt(q,w));
        }

        polygons.pb(p);
    }

    pre_process();
    double ans = 1e22;
    memset(vis, false, sizeof vis);

    for(int i=0;i<n;++i) {
        double L = 0;
        for(auto [x, y] : polygons[i]) {
            if(x < 0)
                L = max(L, abs(x));
        }

        ans = min(ans, L + solve(1<<i, i));
    }

    cout<<fixed<<setprecision(3);
    cout<<ans<<endl;
    
    //--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}