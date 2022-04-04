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
	double x, y;	
	pt(double x=0, double y=0): x(x), y(y) {}
	pt operator *(double c) { return pt(x*c, y*c); }
	double operator *(pt p) { return x*p.x + y*p.y; }
};

// projecao de 'a' em 'b'
pt project(pt a, pt b) { return b * ((a*b) / (b*b)); }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef ONLINE_JUDGE
    freopen("line2.in", "r", stdin);
    freopen("line2.out", "w", stdout);
#endif

    pt a, b;
    cin>>a.x>>a.y>>b.x>>b.y;

    /*
    	
        a
    	^
    	 \
    	  \
    b<-----    	   
    */
    // pt c = project(a, b);
    // cout<<c.x<<" : "<<c.y<<"\n";

    int A = b.x;
    int B = b.y;
    int C = - A*a.x - a.y*B;
    cout<<fixed<<setprecision(10);
    cout<<A<<" "<<B<<" "<<C<<"\n";
}