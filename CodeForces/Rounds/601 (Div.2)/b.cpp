#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
 
using namespace std;
 
typedef long long int ll;
typedef pair<int,int> ii;
const int N = 1010;
 
int t;
int n,m,x;
int a,b,c;
ll ans = 0;
 
 
vector<ii> geladeira;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		ans = 0;
		geladeira.clear();
 
		for(int i=1;i<=n;++i)
		{
			cin>>x;
			geladeira.pb(mp(x,i));
		}
 
		if(m < n || n == 2)
		{
			cout<<"-1\n";
			continue;
		}
		
		sort(all(geladeira));
		int a,b;
		int best = 1000000;
 
		for(int i=0;i<geladeira.size() - 1;++i)
		{
			int dif = geladeira[i+1].f + geladeira[i].f;
			if(dif < best)
			{
				best = dif;
				a = geladeira[i+1].s;
				b = geladeira[i].s;
			}
			ans += dif;			
			m--;
		}
 
		ans+=geladeira[n-1].f + geladeira[0].f;
		m--;
 
		ans+=best*m;
 
		cout<<ans<<"\n";
		for(int i=0;i<geladeira.size() - 1;++i)
		{
			cout<<geladeira[i+1].s<<" "<<geladeira[i].s<<"\n";
		}
 
		cout<<geladeira[n-1].s<<" "<<geladeira[0].s<<"\n";
 
		while(m)
		{
			cout<<a<<" "<<b<<"\n";
			m--;
		}
 
	}
 
	
}