#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
const int N = 1e5;
const int INF = 1e9 + 7;
typedef pair<int,int> ii;
typedef long long int ll;
inline ll gcd(ll a,ll b){	while(b){	a%=b;	swap(a,b);	}	return a;	}


ll a,b,t;

double getdif(ll x)
{
	double proximo = (x*a + (x - 1.0)*b)/(2.0*x - 1.0);
	cout<<fixed<<setprecision(5);
	return abs(proximo - t);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);	
	int casos;

	cin>>casos;
	ll x;
	while(casos--)
	{
		cin>>a>>b>>t;

		x = 2LL;
		if((a+b)/2 >= t)
		{			
			cout<<2<<'\n';
			continue;
		}

		if(a + b != 2LL*t)
		{
			ll cima = b - t;
			ll baixo = (a + b - 2LL*t);
			if(cima%baixo == 0)
			{
				x = cima/baixo;
				cout<<x + x - 1<<"\n";
				continue;
			}
			else
			{
				x = (b-t)/(a + b - 2LL*t);

				if(getdif(x) > getdif(x + 1))
					x = x+1;
				if(getdif(x) > getdif(x - 2))
					x = x - 2;
				
				x += x-1;
				cout<<x<<'\n';	
				continue;							
			}
		}
		else
			cout<<x<<'\n';
		// ll SS = (x*a + (x-1LL)*b)/(2LL*x - 1);
	}
	

}