#include <bits/stdc++.h> // O(N^3)
#define f first			// Floyd-Warshall
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()

using namespace std;

const int N = 110;
const int INF = 1e8;
typedef pair<int,int> ii;

int dist[N][N],tempo,m;
int t,n,a,b,x,saida,ans;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>t;
	while(t--)	
	{
		cin>>n>>saida>>tempo>>m;

		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				dist[i][j] = (i == j) ? 0 : INF;

		for(int i=1;i<=m;++i)
		{
			cin>>a>>b>>x;
			dist[a][b] = min(dist[a][b],x);
		}

		for(int k=1;k<=n;++k)
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j)
					dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);

		ans = 0;
		for(int i=1;i<=n;++i)
			if(dist[i][saida] <= tempo)
				ans++;

		cout<<ans<<"\n";
		if(t>0) cout<<"\n";
	}
}