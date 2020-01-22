#include <bits/stdc++.h>	// O(N*Log)
#define f first				// Dijkstra
#define s second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;

const int N = 20010;
const int INF = 1e9;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

int a,b,x;
int t,n,m,A,B;
int ans,dist[N];

bool seen[N];
vector<ii> graph[N];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


	cin>>t;
	for(int zz=1;zz<=t;++zz)
	{
		cin>>n>>m>>A>>B;
		for(int i=0;i<n;++i)
		{
			graph[i].clear();
			seen[i] = false;
			dist[i] = INF;
		}

		for(int i=0;i<m;++i)
		{
			cin>>a>>b>>x;
			graph[a].pb(mp(x,b));
			graph[b].pb(mp(x,a));
		}

		dist[A] = 0;
		priority_queue<ii, vector<ii> , greater<ii> > fila;
		fila.push(mp(0,A));

		while(!fila.empty())
		{
			int d = fila.top().f;
			int u = fila.top().s;
			fila.pop();
			if(d > dist[u]) continue;
			seen[u] = true;
			if(u == B) break;

			for(int i=0;i<graph[u].size();++i)
			{
				int v = graph[u][i].s;
				int dd = graph[u][i].f;
				if(dist[u] + dd < dist[v] && !seen[u])
				{
					dist[v] = dist[u] + dd;
					fila.push(mp(dist[v],v));
				}
			}
		}
		cout<<"Case #"<<zz<<": ";
		if(dist[B] == INF) cout<<"unreachable\n";
		else cout<<dist[B]<<"\n";
	}	

}