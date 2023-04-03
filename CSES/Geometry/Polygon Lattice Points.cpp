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

typedef long long int ll;
struct point {   
    ll x, y;    
    point(ll x=0,ll y=0) : x(x), y(y){}
    point operator-(const point &a){
        return point(x-a.x,y-a.y);
    }
};

vector<point> p;

ll cross(point v1, point v2) {
    return v1.x*v2.y - v1.y*v2.x;
}

ll area(vector<point> &p) {
    ll ans = 0;
    for(int i=2;i<sz(p);++i)
        ans += cross(p[i]-p[0],p[i-1]-p[0]);
    return ans;
}

ll boundary(vector<point> &A) {
    int n = sz(A);
    ll ats = n;

    for(int i=0; i<n; i++) {
        ll dx = (A[i].x - A[(i+1)%n].x);
        ll dy = (A[i].y - A[(i+1)%n].y);
        ats+=abs(__gcd(dx,dy)) - 1;
    }
    return ats;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    p.resize(n);
    for(int i=0;i<n;++i)
        cin>>p[i].x>>p[i].y;
    
    ll S = area(p);
    ll B = boundary(p);
    ll I = (abs(S) - B + 2LL)/2LL;

    cout<<I<<" "<<B<<"\n";
}