#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 2e5 + 7;
const double INF = 1e9;
const double PI = acos(-1);

typedef long long ll;
typedef pair<double,double> point;

double dist(point a , point b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y-b.y)*(a.y-b.y));
}  

double dist_seg(point a,point b,point p)
{
	point v1 = {p.x - a.x,p.y - a.y};
	point v2 = {b.x - a.x,b.y - a.y};
	double dot = v1.x*v2.x + v1.y*v2.y;	

	double l1 = (v1.x*v1.x + v1.y*v1.y);
	double l2 = (v2.x*v2.x + v2.y*v2.y);
	double cosenoo = dot/(sqrt(l1)*sqrt(l2));
	if(dot < 0.0 || sqrt(l1)*cosenoo > sqrt(l2)) return min(dist(a,p),dist(b,p));

	double aux = sqrt((l1*l2 -dot*dot)/(l1*l2) )*sqrt(l1);
	return aux;	
}

point O,now,v[N];
int n;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	double menor = INF,maior = 0.0;

	cin>>n>>O.x>>O.y;
	for(int i=0;i<n;++i)
	{
		cin>>now.x>>now.y;

		v[i] = now;
		double atual = dist(now,O);

		if(atual < menor)
			menor = atual;
		if(atual > maior)
			maior = atual;
	}

	for(int i=0;i<n;++i)
	{
		point c1,c2;

		c1 = v[i],c2 = v[(i+1)%n];
		double d = dist_seg(c1,c2,O);

		menor = min({d,menor,dist(c1,O)});
	}

	cout<<fixed<<setprecision(18);
	cout<<acos(-1)*(maior*maior - menor*menor)<<"\n";
}