#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
using namespace std;

const int N = 110;
const int INF = 1e6 + 1e6;

int dist[N][N][N];
int n,m,q;
int a,b,c;

void init(int n)
{
	for(int k=0;k<=n;++k)
		for(int i=0;i<=n;++i)
			for(int j=0;j<=n;++j)
				dist[k][i][j] = INF;
	
	for(int k=0;k<=n;++k)
		for(int i=0;i<=n;++i)
			dist[k][i][i] = 0;
}

void solve(int n)
{
	for(int k=2;k<=n;++k)
	{
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				dist[k][i][j] = min(dist[k-1][i][j], dist[k-1][i][k] + dist[k-1][k][j]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


	while(cin>>n>>m)
	{
		init(n);

		for(int i=1;i<=m;++i)
		{
			cin>>a>>b>>c;
			dist[1][a][b] = c;
			dist[1][b][a] = c;
		}

		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				dist[1][i][j] = min(dist[1][i][j],dist[1][i][1] + dist[1][1][j]);

		solve(n);

		cin>>q;
		while(q--)
		{
			cin>>a>>b>>c;
			if(dist[c][a][b] == INF)
				cout<<"-1\n";
			else
				cout<<dist[c][a][b]<<"\n";
		}
	}

}