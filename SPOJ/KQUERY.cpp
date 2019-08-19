/*
	KQUERY SPOJ
	Leonardo Su
*/
#include <bits/stdc++.h>  // KQUERY SPOJ AC!
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define N 30100
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,ii> iiii;
typedef long long int ll;

int BIT[N],sum;
int n,q;
int a,b,c,d;

vector<iiii> Q;
vector<ii> resp; // pos,resp
vector<ii> save; // valor,pos

int query(int i)
{
	int A=0;
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
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a;
		save.pb(mp(a,i));
		update(i,1);
	}

	cin>>q;

	for(int i=0;i<q;++i)
	{
		cin>>a>>b>>c;
		Q.pb(mp(mp(c,i),mp(a,b)));
	}

	int pos=0;

	sort(save.begin(),save.end());
	sort(Q.begin(),Q.end());

	for(int i=0;i<Q.size();++i)
	{
		c=Q[i].f.f,d=Q[i].f.s; a=Q[i].s.f,b=Q[i].s.s;

		while(pos<n && save[pos].f<=c)
			update(save[pos].s,-1),pos++;
		sum=query(b)-query(a-1);
		resp.pb(mp(d,sum));
	}

	sort(resp.begin(),resp.end());
	for(int i=0;i<resp.size();++i)
		cout<<resp[i].s<<"\n";
}