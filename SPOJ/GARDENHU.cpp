#include "bits/stdc++.h" //https://www.spoj.com/problems/GARDENHU/
#define endl '\n'
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
mt19937 rng((ll) std::chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e4+5;
struct pt {
    ll x,y;
    pt(ll x=0,ll y=0):x(x),y(y){}
    bool operator<(pt p){return tie(x,y)<tie(p.x,p.y);}
    bool operator==(pt p){return tie(x,y)==tie(p.x,p.y);}
    pt operator-(pt p){return pt(x-p.x,y-p.y);}
    ll cross(pt p) {return x*p.y-y*p.x;}
    ll cross(pt a, pt b) {return (a-*this).cross(b-*this);}
} ch[N];

vector<pt> convexHull(vector<pt> &pts) {
    if (sz(pts) <= 1) return pts;
    sort(all(pts));
    vector<pt> h(sz(pts)+1);
    int s = 0, t = 0;
    for (int it = 2; it--; s = --t, reverse(all(pts)))
        for (pt p : pts) {
            while (t >= s + 2 && h[t-2].cross(h[t-1], p) <= 0) t--;
            h[t++] = p;
        }
    return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    double timing = clock();
    
    int n;
    cin>>n;
    vector<pt> pts(n);
    for(auto &p:pts) 
        cin>>p.x>>p.y;
    auto ch = convexHull(pts);
    
    double ans = 0;
    n = sz(ch);
    for(int i=0;i<n;++i) {
        int j = (i+1)%n;
        ll dx=ch[i].x-ch[j].x;
        ll dy=ch[i].y-ch[j].y;
        ans += sqrt(dx*dx+dy*dy);
    }

    cout<<round(ans)<<endl;
    //--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}