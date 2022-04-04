#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
#define debug(...) cerr<<"["<<#__VA_ARGS__<<": "<<(__VA_ARGS__)<<"]\n"
#define debugarr(a, b) for(int i=0;i<b;++i)\
cerr<<a[i]<<" "; cerr<<endl
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const double PI = acos(-1);
double EPS = 1e-6;
int cmpD(double x, double y=0, double tol = EPS) { return (x <= y+tol) ? (x+tol < y) ? -1 : 0 : 1; }
double positive_angle(double a) {
    while(cmpD(a) < 0) a += 2*PI;
    while(cmpD(a, 2*PI) >= 0) a -= 2*PI;
    return a;
}

int main() // The polar angle of a point
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifdef ONLINE_JUDGE
	freopen("angle1.in", "r", stdin);
	freopen("angle1.out", "w", stdout);
	#endif
	int x, y;
	cin>>x>>y;
	
	double angle = atan2(y, x);
	cout<<fixed<<setprecision(10);
	cout<<positive_angle(angle)<<"\n";
}