#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define EPS 1e-7
using namespace std;
 
typedef long long int ll;
 
typedef pair<double,double> point;
 
vector<point> lamppost;
 
double dist(point a,point b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
 
double Area(point a,point b,point c)
{
	double ans = a.x*b.y + b.x*c.y + c.x*a.y;
	ans -= 	 a.y*b.x + b.y*c.x + c.y*a.x;
	return abs(ans)/2.0;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
 
	point A,B,C;
 
	cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y;
 
	double d;
	int k;
 
	cin>>k;
 
	double coss = (B.x - A.x)/dist(B,A);
	double senn = (B.y - A.y)/dist(B,A);
 
	for(int i=0;i<k;++i) // A -> B
	{
		cin>>d;
		if(i == k-1 || i == 0)
			lamppost.pb(mp(A.x+d*coss,A.y+d*senn));
	}
 
	cin>>k;
	coss = (C.x - B.x)/dist(C,B);
	senn = (C.y - B.y)/dist(C,B);
	
	for(int i=0;i<k;++i) // B -> C
	{
		cin>>d; 
		if(i == k-1 || i == 0)
		lamppost.pb(mp(B.x+d*coss,B.y+d*senn));
	}
 
	cin>>k;
	coss = (A.x - C.x)/dist(A,C);
	senn = (A.y - C.y)/dist(A,C);
 
	for(int i=0;i<k;++i) // C -> A
	{
		cin>>d;
		if(i == k-1 || i == 0)
			lamppost.pb(mp(C.x+d*coss,C.y+d*senn));
	}
 
	double ans = 0;
 
	for(int i=0;i<lamppost.size();++i) 
		for(int j=i+1;j<lamppost.size();++j)
			for(int z=j+1;z<lamppost.size();++z)
				{
					double xx = Area(lamppost[i],lamppost[j],lamppost[z]);
					if(xx + EPS > ans)
						ans = xx;
				}
 
 
	cout<<fixed<<setprecision(10);
	cout<<ans<<"\n";
}