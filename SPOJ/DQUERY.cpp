#include <bits/stdc++.h> //Leonardo Su
#define f first         // DQUERY SPOJ 26/07/2017
#define s second	// BIT solution
#define pb push_back
#define mp make_pair
#define N 30010
#define M 1000010
using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;
typedef pair<ii,ii> iiii;

ll BIT[N];
int prev[M],n,q;
int T,a,b,V,x;

vector<iiii> Q;
vector<ii> resp;

ll query(int i)
{
	ll A=0;
	while(i>0)
	{
		A+=BIT[i];
		i-=i&-i;
	}
	return A;
}

void update(int i,int x)
{
	while(i<N)
	{
		BIT[i]+=x;
		i+=i&-i;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	memset(prev,-1,sizeof prev);
	cin>>n;

	for(int i=1;i<=n;++i)
	{
		cin>>x;
		Q.pb(mp(mp(i,0),mp(x,i)));
	}

	cin>>q;

	for(int i=0;i<q;++i)
	{
		cin>>a>>b;
		Q.pb(mp(mp(b,1),mp(i,a)));
	}

	sort(Q.begin(),Q.end());

	for(int i=0;i<Q.size();++i)
	{
		T=Q[i].f.s,b=Q[i].f.f;	a=Q[i].s.s,V=Q[i].s.f;

		if(T==0)
		{
			if(prev[V]!=-1)
				update(prev[V],-1);
			update(a,1);
			prev[V]=a;
		}

		else
		{
			ll sum=query(b) - query(a-1);
			resp.pb(mp(V,sum));
		}
	}

	sort(resp.begin(),resp.end());

	for(int i=0;i<resp.size();++i)
		cout<<resp[i].s<<"\n";

}