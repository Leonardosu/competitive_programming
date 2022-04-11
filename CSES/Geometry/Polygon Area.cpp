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

ll areaPolygon(vector<pt> &polygon)
{
	ll area = 0;
	int j = polygon.size() - 1;
	for(int i=0;i<(int)polygon.size();++i)
	{
		area += (polygon[j].x + polygon[i].x) * (polygon[j].y - polygon[i].y);
		j = i;
	}

	return abs(area);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin>>n;
	vector<pt> polygon(n);
	for(pt &point : polygon)
		cin>>point.x>>point.y;
	
	cout<<areaPolygon(polygon)<<"\n";
}