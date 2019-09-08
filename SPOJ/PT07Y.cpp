/*
	PT07Y SPOJ
	Leonardo Su
*/
#include <bits/stdc++.h>
#define N 10010
using namespace std;

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

bool is_tree(int n)
{
	for(int i=1;i<=n;++i)
		if(!visited[i])
			return false;
	return true;
}

int n,m,a,b;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin>>n>>m;
	
	for(int i=1;i<=n;++i)	visited[i] = false;

	for(int i=0;i<m;++i)
	{
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1);

	if(m == n-1 && is_tree(n))
		cout<<"YES\n";
	else
		cout<<"NO\n";
}