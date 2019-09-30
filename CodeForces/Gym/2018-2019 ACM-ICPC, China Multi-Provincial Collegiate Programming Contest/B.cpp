#include <bits/stdc++.h> //Geometry
using namespace std;

int n,t;
const int N = 59;
const double PI = acos(-1);

struct point
{
	double x,y;	
};

point pontos[N];
point M;

double dist(point a,point b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

double angulo(point a,point o,point b)
{
	double x = dist(a,b);
	double la = dist(a,o);
	double lb = dist(b,o);

	return acos( (la*la + lb*lb - x*x)/(2*la*lb) );
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>t;
	for(int z = 1;z<=t;++z)
	{
		cin>>n;
		for(int i=1;i<=n;++i)
			cin>>pontos[i].x>>pontos[i].y;
		
		cin>>M.x>>M.y;
		
		pontos[0].x = pontos[n].x;	pontos[0].y = pontos[n].y;
		pontos[n+1].x = pontos[1].x;	pontos[n+1].y = pontos[1].y;

		cout<<fixed<<setprecision(3);
		double ans = 0;

		for(int i=1;i<=n;++i)
		{
			double ang = (PI - angulo(pontos[i-1],pontos[i],pontos[i+1]));
			ans+=ang*dist(M,pontos[i]);
		}
		cout<<"Case #"<<z<<": "<<ans<<"\n";
	}

}