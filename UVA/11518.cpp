#include <bits/stdc++.h> // 11518-Dominos 2
#define f first		
#define s second
#define mp make_pair
#define pb push_back
#define N 10010
using namespace std;
typedef pair<int,int> ii;

int t,n,m,l,a,b;
vector<int> graph[N];
bool visited[N];

void dfs(int x)
{
	visited[x] = true;

	for(int i=0;i<graph[x].size();++i)
	{
		int v = graph[x][i];
		if(!visited[v])
			dfs(v);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin>>t;
	while(t--)
	{
		cin>>n>>m>>l;	int ans = 0;
		for(int i=0;i<=n;++i) graph[i].clear(),visited[i] = false;
	
		for(int i=0;i<m;++i)
		{
			cin>>a>>b;
			graph[a].pb(b);
		}

		for(int i=0;i<l;++i)
		{
			cin>>a;
			dfs(a);
		}

		for(int i=1;i<=n;++i)
			if(visited[i]) ans++;
		cout<<ans<<"\n";
	}
}