#include <bits/stdc++.h>	// Dijkstra 2D
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;

const int N = 1005;
const int INF = 1e9;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int a,b,x;
int t,n,m,A,B;
int ans,dist[N][N];
int data[N][N];

int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};

bool check(int x,int y)
{
	if(x >=n || y>=m || x < 0 || y < 0) return false;
	return true; 
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				dist[i][j] = INF;

		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				cin>>data[i][j];

		priority_queue<iii, vector<iii> , greater<iii> > fila;

		dist[0][0] = data[0][0];
		fila.push(mp(data[0][0],mp(0,0)));
		while(!fila.empty())
		{
			int d = fila.top().f;
			int x = fila.top().s.f;
			int y = fila.top().s.s;
			fila.pop();
			if(d > dist[x][y]) continue;
			if(x == n-1 && y == m-1) break;
			for(int k=0;k<4;++k)
			{
				int xx = dx[k] + x;
				int yy = dy[k] + y;
				if(check(xx,yy) && dist[x][y] + data[xx][yy] < dist[xx][yy])
				{
					dist[xx][yy] = dist[x][y] + data[xx][yy];
					fila.push(mp(dist[xx][yy],mp(xx,yy)));
				}
			}

		}

		cout<<dist[n-1][m-1]<<'\n';
	}	

}