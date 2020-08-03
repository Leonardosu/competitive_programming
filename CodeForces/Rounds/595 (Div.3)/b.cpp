#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
using namespace std;
 
const int N = 200010;
const int INF = 1e8;
 
typedef long long int ll;
typedef pair<int,int> ii;
 
int n,q;
int a,x;
 
vector<int> graph[N];
 
int day[N];
bool visited1[N],visited2[N];
int contador = 0;
 
void dfs1(int x)
{
	contador++;
 
	visited1[x] = true;
 
	for(int i=0;i<graph[x].size();++i)
	{
		int u = graph[x][i];
		if(!visited1[u])
			dfs1(u);
	}
 
}
 
void dfs2(int x,int valor)
{
	visited2[x] = true;
	day[x] = valor;
 
	for(int i=0;i<graph[x].size();++i)
	{
		int u = graph[x][i];
		if(!visited2[u])
			{
				day[u] = valor;
				dfs2(u,valor);
			}
 
	}
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
	cin>>q;
	while(q--)
	{
		cin>>n;
		for(int i=1;i<=n;++i)
			graph[i].clear();
		for(int i=1;i<=n;++i)
		{
			cin>>x;
			graph[i].pb(x);
			day[i] = 0;
			visited1[i] = false;
			visited2[i] = false;
 
		}
 
		for(int i=1;i<=n;++i)
		{
			if(!visited1[i])
			{
				contador = 0;
				dfs1(i);
				if(graph[i].size() == 1 && graph[i][0] == i)
					day[i] = 1;
				else
					dfs2(i,contador);
			}
		}
 
		for(int i=1;i<=n;++i)
			cout<<day[i]<<" ";
		cout<<"\n";
	}
 
 
}