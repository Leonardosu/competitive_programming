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

const int EPS = 1e-6;
const double PI = acos(-1);
int cmpD(double x, double y=0, double tol = EPS) { return (x <= y+tol) ? (x+tol < y) ? -1 : 0 : 1; }
struct pt {
	using ptType = long long int;	
    ptType x, y;
    pt(ptType x=0, ptType y=0): x(x), y(y) {}
    pt operator +(pt p) { return pt(x+p.x, y+p.y); }
    pt operator -(pt p) { return pt(x-p.x, y-p.y); }
    pt operator *(ptType c) { return pt(x*c, y*c); }
    pt operator /(ptType c) { return pt(x/c, y/c); }
    ptType operator *(pt p) { return x*p.x + y*p.y; }
    ptType operator %(pt p) { return x*p.y - y*p.x; }
    friend ostream& operator <<(ostream& o, pt p) { return o << "(" << p.x << "," << p.y << ")"; }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    vector<pt> points(n);
    for(auto &p : points) {
    	cin>>p.x>>p.y;
    }

   	// sort(ALL(points), [](const pt &a, const pt &b) -> bool {
   	// 	return (a.x == b.x ? a.y < b.y : a.x < b.x);
   	// });

    ll ans = 0;
    for(int i=0;i<n;++i) 
    	for(int j=i+1;j<n;++j) {
    		ll left = -1, right = -1;
    		pt v = points[j] - points[i];

    		for(int k=0;k<n;++k) {
    			if(k != i && k != j) {
    				ll res = v%points[k];
    				if(res < 0) left = max(left, -res);
    				else right = max(right, res);
    			}
    		}

    		if(left != -1 && right != -1)
				ans = max(ans, left + right);
    	}
    
    cout<<fixed<<setprecision(12);
    cout<<(long double) ans / 2.0<<"\n";
}