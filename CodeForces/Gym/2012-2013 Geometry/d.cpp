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
	ll x, y;	
};

double areaPolygon(vector<pt> &polygon) {
	ll area = 0;
	int j = polygon.size() - 1;
	for(int i=0;i<(int)polygon.size();++i) {
		area += (polygon[j].x + polygon[i].x) * (polygon[j].y - polygon[i].y);
		j = i;
	}

	return abs(area)/2.0;
}

int main() //Area of the triangle
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifdef ONLINE_JUDGE
	freopen("area1.in", "r", stdin);
	freopen("area1.out", "w", stdout);
	#endif

	int n = 3;
	vector<pt> polygon(n);
	for(pt &point : polygon)
		cin>>point.x>>point.y;

	cout<<fixed<<setprecision(10);
	cout<<areaPolygon(polygon)<<"\n";
}