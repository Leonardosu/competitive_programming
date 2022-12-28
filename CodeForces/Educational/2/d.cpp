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

const double EPS = 1e-6;
const double PI = acos(-1);

struct pt {
	long double x, y;
	pt(double x_ = 0, double y_ = 0) : x(x_), y(y_) {};
	long double dist(pt o){ return sqrt((o.x - x)*(o.x - x) + (o.y - y)*(o.y - y));}
};

struct circle {
	pt center;
	long double radius;
	circle(pt p = pt(), double radius_ = 0): center(p), radius(radius_) {};
};

long double angle(long double r1, long double d, long double r2) {
	//r2^2 = r1^2 + d^2 - 2r1dcos
	return acos((r1*r1 + d*d - r2*r2)/(r1*d*2.0));
}

long double circleIntersectionArea(circle c1, circle c2) {
	long double totalArea = 0, r1 = c1.radius, r2 = c2.radius;
	long double dist = c1.center.dist(c2.center);

	if (r1 + r2 < dist) {
		totalArea = 0;
	} else if (dist <= fabs(r1 - r2)) {
		double r = min(r1, r2);
		totalArea = r * r * PI;
	} else {
		long double tetha1 = angle(r1, dist, r2);
		long double s1 = r1 * r1 *(tetha1 - sin(2*tetha1)/2.0);

		long double tetha2 = angle(r2, dist, r1);
		long double s2 = r2 * r2 * (tetha2 - sin(2*tetha2)/2.0);
		// cout<<tetha1<<" | "<<tetha2<<"\n";
		totalArea += s1 + s2;
    }
	
    return totalArea;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    circle c1, c2;
    pt center;
    cin>>center.x>>center.y>>c1.radius;
    c1.center = center;

    cin>>center.x>>center.y>>c2.radius;
    c2.center = center;

    cout<<fixed<<setprecision(16);
    cout<<circleIntersectionArea(c1, c2)<<"\n";
}