#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define N
 
using namespace std;
 
typedef long long int ll;
typedef pair<int,int> ii;
 
ll t,x;
ll n,m,sum;
 
vector<ll> ciclo;
bool mark[12];
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
	cin>>t;
 
	while(t--)
	{
		ciclo.clear(); for(int i=0;i<=10;++i) mark[i] = false;
		sum = 0;
 
		cin>>n>>m;
 
		ll multiplos = n/m;
		x = m%10;
 
		while(true)
		{
			x = x%10;
			if(!mark[x])	
				ciclo.pb(x),mark[x] = true;
 
			else
				break;
			x+=m;
		}
 
		for(int i=0;i<ciclo.size();++i)
			sum+=ciclo[i];
 
		sum = (multiplos/ciclo.size())*sum;
 
		x = multiplos%ciclo.size();
 
		for(int i=0;i<x;++i)
			sum+=ciclo[i];
		
		cout<<sum<<"\n";
	}
 
}