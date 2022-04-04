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

struct pt{
	int x, y;	

	double norm()
	{
		return sqrt(x*x + y*y);
	}
};

int dotProd(pt a, pt b)
{
	return a.x*b.x + a.y*b.y;
}

int main() //The angle between vectors
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("angle2.in", "r", stdin);
	freopen("angle2.out", "w", stdout);

	pt a, b;
	cin>>a.x>>a.y;
	cin>>b.x>>b.y;
	double prod = dotProd(a, b);
	// a.b = |a|.|b|.cos
		
	double angle = acos(prod/(a.norm()*b.norm()));
	cout<<fixed<<setprecision(10);
	cout<<angle<<"\n";
}