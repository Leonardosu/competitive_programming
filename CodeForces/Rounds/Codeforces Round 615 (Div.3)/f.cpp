#include <bits/stdc++.h> 
#define f first			// Leonardo_su 22/01/2020
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
 
const int M = 19;
const int N = 200110;
const int INF = 1e9;
 
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef long long int ll;
 
vector<int> graph[N];
int n,a,b,c;
 
int pai[N],dist[N],nivel[N];
int dp[M][N],sum;
 
 
void dfs(int x,int u)
{
	pai[x] = u;
	for(int i=0;i<graph[x].size();++i)
	{
		int v = graph[x][i];
		if(v == u) continue;
		dist[v] = dist[x] + 1;
		dfs(v,x);
	}
}
 
int best()
{
	int ans = 0,id;
	for(int i=1;i<=n;++i)
		if(ans < dist[i])
			ans = dist[i],id = i;
 
	sum = ans;
	return id;
}
 
int lca(int x,int y)
{
	if(dist[x] < dist[y]) swap(x,y);
	for(int i = M - 1;i>=0;--i)
		if(dist[x] - (1<<i) >= dist[y])
			x = dp[i][x];
	if(x == y) return x;
 
	for(int i = M - 1;i>=0;--i)
		if(dp[i][x] != 0 && dp[i][x] != dp[i][y])
			x = dp[i][x],y = dp[i][y];
	return dp[0][x];
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
	cin>>n;
	for(int i=1;i<n;++i)
	{
		cin>>a>>b;
		graph[a].pb(b);
		graph[b].pb(a);
		
		nivel[a]++;
		nivel[b]++;
	}
	
	for(int i=1;i<=n;++i)
		pai[i] = 0;
 
	int A,B,C = -1;
	dist[1] = 0;
	dfs(1,0);
	A = best();
 
	dist[A] = 0;
	dfs(A,0);
	B = best();
 
 
	for(int i=0;i<M;++i)
		for(int j=1;j<=n;++j)
			dp[i][j] = 0;
 
	for(int i=1;i<=n;++i)
		dp[0][i] = pai[i];
 
	for(int i=1;i<M;++i)
		for(int j=1;j<=n;++j)
			dp[i][j] = dp[i-1][ dp[i-1][j] ];
 
 
	int ans = 0;
	queue<int> fila;
	for(int i=1;i<=n;++i)
		if(i != A && i!= B && nivel[i] == 1)
		{
			C = i;
			fila.push(i);
		}
 
	for(int i=1;i<=n;++i)
	{
		if(i == A || i == B) continue;
		
		int v = lca(i,B);
		if(dist[i] - dist[v] > ans)
		{
			ans = dist[i] - dist[v];
			C = i;
		}
	}
	
	if(C == -1)
	{
		for(int i=1;i<=n;++i)
			if(i != A && i != B)
			{
				C = i;
				break;
			}
	}
	sum+=ans;
	cout<<sum<<"\n";
	cout<<A<<" "<<B<<" "<<C<<"\n";
}