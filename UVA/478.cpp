#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define db double
#define EPS 0.000001
using namespace std;
 //										******Problem D Codepit*********
 //										******478 UVA/AC ;) *********

typedef pair<db,db> point;
typedef pair<point,point> pp;
typedef pair<point,pp> T1; // Raio,x,y oouu A,B,C
typedef pair<db,point> T2; // (Raio),(x,y)
typedef pair<point,point> retangulo; // Esquerda cima,direita baixo
bool achou=false;

char op;
vector<T1> triangle;
vector<T2> cicle;
vector<retangulo> rectangle;


double Area(point a, point b, point c)
{
	return fabs((a.f*(b.s-c.s) + b.f*(c.s-a.s)+ c.f*(a.s-b.s)));
}

db dist(point a,point b)
{

	return sqrt(pow(a.f-b.f,2)+pow(a.s-b.s,2));
}

bool igual(point a,point b)
{
	if(fabs(a.f-b.f)<EPS && fabs(a.s-b.s)<EPS)
		return true;
	return false;
}

bool na_reta(point X,point a,point b) // y=A.x+B
{
	double A=(a.s-b.s)/(a.f-b.f);
	double B=(a.s-A*a.f);
	if(fabs(B+X.f*A-X.s)<EPS)
		return true;
	return false;
}
bool tri(point d, T1 X)
{
	db S1=Area(d,X.f,X.s.f); // Areas dos triangulos com D
	db S2=Area(d,X.f,X.s.s);
	db S3=Area(d,X.s.f,X.s.s);
	db S4=Area(X.f,X.s.f,X.s.s);

	if(EPS>S1+S2+S3-S4 && (!igual(d,X.f) && !igual(d,X.s.f) && !igual(d,X.s.s)))
		if(!na_reta(d,X.f,X.s.s) && !na_reta(d,X.f,X.s.f) && !na_reta(d,X.s.f,X.s.s))
		return true;

	return false;
}

bool circulo(point d,T2 X)
{
	if(dist(d,X.s)<X.f)
		return true;
	return false;
}

bool retangu(point d, retangulo X)
{
	if(d.f>X.f.f && d.f<X.s.f)
		if(d.s<X.f.s && d.s>X.s.s)
			return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	vector<pair<char,int> > fila;
	int qnt=1,atual=1;

	point a,b,c;
	db r;

	while(cin>>op && op!='*')
	{
		if(op=='r')
		{
			cin>>a.f>>a.s>>b.f>>b.s;
			rectangle.pb(retangulo(a,b));
		}

		if(op=='c')
		{
			cin>>a.f>>a.s>>r;
			cicle.pb(mp(r,a));
		}

		if(op=='t')
		{
			cin>>a.f>>a.s>>b.f>>b.s>>c.f>>c.s;
			triangle.pb(mp(a,mp(b,c)));
		}

			fila.pb(mp(op,qnt));
		qnt++;
	}

	
	while(cin>>a.f>>a.s && (a.f!=9999.9 && a.s!=9999.9))
	{
		achou=false; int q=0,w=0,e=0; // triangulo,retangulo,circulo
		for(int i=0;i<fila.size();++i)
		{
			if(fila[i].f=='r')
			{
				if(retangu(a,rectangle[w]))
				{
					achou=true;
					cout<<"Point "<<atual<<" is contained in figure "<<fila[i].s<<"\n";
				}
				w++;
			}

			else if(fila[i].f=='c')
			{
				if(circulo(a,cicle[e]))
				{
					achou=true;
					cout<<"Point "<<atual<<" is contained in figure "<<fila[i].s<<"\n";
				}
				e++;
			}

			else if(fila[i].f=='t')
			{
				if(tri(a,triangle[q]))
				{
					achou=true;
					cout<<"Point "<<atual<<" is contained in figure "<<fila[i].s<<"\n";
				}
				q++;
			}

		}

		if(!achou)
			cout<<"Point "<<atual<<" is not contained in any figure\n";

		atual++;
	}

}