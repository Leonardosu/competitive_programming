#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
const int N = 2e5 + 7;
const int INF = 1e9;
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;

int t;
vector<int> g[N],h[N];
vector<int> path;
int dist1[N],dist2[N];
int n,m,best;

void bfs(int (&dist)[N] , vector<int> g[N],int ini)
{
	for(int i=0;i<=n;++i) dist[i] = INF;
	dist[ini] = 0;

	queue<ii> fila;
	fila.push({0,ini});

	while(!fila.empty())
	{
		ii now = fila.front();
		fila.pop();
		for(int i=0;i<g[now.s].size();++i)
		{
			int u = g[now.s][i];
			if(dist[u] > dist[now.s] + 1)
			{
				dist[u] = dist[now.s] + 1;
				fila.push({dist[u],u});
			}
		}
	}	
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


	int q;
	cin>>n>>m;
	for(int i=0;i<m;++i)
	{
		int x,y;
		cin>>x>>y;
		g[x].pb(y);
		h[y].pb(x);
	}
	
	cin>>q;
	path.resize(q);
	for(int i=0;i<q;++i)
		cin>>path[i];

	bfs(dist1,g,path[0]);
	bfs(dist2,h,path[q-1]);
		
	// for(int i=1;i<=n;++i)
	// 	cout<<dist[i]<<",";
	
	bool rota = false;
	int a = 0,b = 0;

	for(int i=0;i<path.size()-1;++i)
	{
		int u = path[i];
		int next = path[i+1];

		if(dist2[u] != dist2[next] + 1)
			a++;
		else
		{
			int caras = 0; 
			for(int v : g[u])
			{
				if(dist2[u] == dist2[v] + 1)
					caras++;
			}
			if(caras > 1) b++;
		}
	}
	
	cout<<a<<" "<<a+b<<"\n";	
}