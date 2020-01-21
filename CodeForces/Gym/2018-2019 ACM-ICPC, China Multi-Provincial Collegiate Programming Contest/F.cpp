#include <bits/stdc++.h> // Graph,O(n^3)
#define f first			// Floyd-Warshall
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;

const int N = 210;
const int INF = 1e9;
typedef pair<int,int> ii;

int dist[N][N][N];
int t,n,q,x,u,v,w;
int total,maior;

vector<ii> lista;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>t;
	for(int zz = 1;zz<=t;++zz)
	{
		
		cin>>n>>q;

		lista.clear();
		for(int lv = 0;lv<=n+1;++lv)
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j)
					dist[lv][i][j] = INF;				
		
		for(int i=1;i<=n;++i)		
		{
			cin>>x;
			lista.pb(mp(x,i));
		}
		
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				cin>>dist[0][i][j];			
		

		sort(all(lista));
		for(int lv = 1;lv<=n;++lv)
		{
			int u = lista[lv - 1].s;
			for(int i=1;i<=n;++i)		
				for(int j=1;j<=n;++j)
					dist[lv][i][j] = min(dist[lv - 1][i][j],dist[lv - 1][i][u] + dist[lv - 1][u][j]);
			
		}

		cout<<"Case #"<<zz<<":\n";
		while(q--)
		{
			cin>>u>>v>>w;
			int ans = dist[0][u][v];
			for(int i=0;i<n;++i)
			{
				if(lista[i].f <= w)
					ans = min(ans,dist[i+1][u][v]);
				else
					break;
			}

			cout<<ans<<"\n";
		}
		
	}
}