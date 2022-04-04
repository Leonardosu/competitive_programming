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

struct pt{
    double x,y;
    pt(double x=0, double y=0): x(x), y(y) {}
    pt operator +(pt p) { return pt(x+p.x, y+p.y); }
    pt operator -(pt p) { return pt(x-p.x, y-p.y); }    
    pt operator *(double c) { return pt(x*c, y*c); }
    pt operator /(double c) { return pt(x/c, y/c); }
    double len(){
        return sqrt(x*x + y*y);
    }
};

int main() //The bisector
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef ONLINE_JUDGE
    freopen("bisector.in", "r", stdin);
    freopen("bisector.out", "w", stdout);
#endif

    pt x, y, z;
    array<pt, 3> pts;
    for(auto &point : pts)
        cin>>point.x>>point.y;
    
    pts[1] = pts[1]-pts[0];
    pts[2] = pts[2]-pts[0];

    pt v1 = pts[1] * pts[2].len();
    pt v2 = pts[2] * pts[1].len();
    pt k = v1 + v2 + pts[0];
    
    // k = k / k.len(); 
    /*
            v1'
          /
         /
        O - -- - - - K
         \
          \
           v2'
    */
    double A = k.y - pts[0].y;
    double B = pts[0].x - k.x;
    double C = -A*pts[0].x - B*pts[0].y;
    

    cout<<fixed<<setprecision(10);
    cout<<A<<" "<<B<<" "<<C<<"\n";    
}