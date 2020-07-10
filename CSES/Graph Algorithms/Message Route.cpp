#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int INF = 1e9;

typedef long long int ll;
typedef pair<int,int> ii;

vector<int> g[N];
int n,m,ans;
int dist[N],pai[N];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(int i=0;i<m;++i)
	{
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	for(int i=1;i<=n;++i) dist[i] = INF,pai[i] = -1;
	dist[1] = 1;

	queue<int> fila;
	fila.push(1);
	while(!fila.empty())
	{
		int now = fila.front();
		fila.pop();
		if(now == n) break;
		for(int i=0;i<g[now].size();++i)
		{
			int u = g[now][i];
			if(dist[u] > dist[now] + 1)
			{
				pai[u] = now;
				dist[u] = dist[now] + 1;
				fila.push(u);
			}
		}
	}

	vector<int> path;
	if(dist[n] == INF) cout<<"IMPOSSIBLE\n";
	else
	{
		cout<<dist[n]<<"\n";
		int now = n;

		while(now != -1)
		{
			path.push_back(now);
			now = pai[now];
		}

		for(int i=path.size()-1;i>=0;--i)
			cout<<path[i]<<" ";
		cout<<'\n';
	}
}