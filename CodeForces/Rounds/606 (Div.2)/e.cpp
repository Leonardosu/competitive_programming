#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;

const int N = 2e5 + 7;
const int INF = 1e9;
const int MOD = 1e9 + 7;

typedef long long int ll;

int n,m,a,b;
bool d1[N],d2[N];
vector<int> g[N];

void dfs(bool (&d)[N],int x,int y)
{
	if(x == y) return;
	d[x] = true;
	for(auto e : g[x])
		if(!d[e] && e != y)
			dfs(d,e,y);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>a>>b;

		for(int i=1;i<=n;++i)
		{
			d1[i] = d2[i] = false;
			g[i].clear();
		}

		for(int i=0;i<m;++i)
		{
			int x,y;
			cin>>x>>y;
			g[x].pb(y);
			g[y].pb(x);
		}

		dfs(d1,a,b);
		dfs(d2,b,a);
		ll A = -1,B = -1;
		for(int i=1;i<=n;++i)
		{
			if(d1[i] && d2[i])
				continue;
			if(d1[i])	
				A++;			
			if(d2[i])	
				B++;
		}
				
		cout<<A*B<<"\n";
	}

}