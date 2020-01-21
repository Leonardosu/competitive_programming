#include <bits/stdc++.h> // O(N^3) AC
#define f first			// Floyd-Warshall
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()

using namespace std;

const int N = 111;
const int INF = 1e8;
typedef pair<int,int> ii;

int a,b;
int dist[N][N],sum,qnt,maior,t;
set<int> vertex;
vector<int> pontos;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	bool flag;

	while(1)
	{	
		pontos.clear(); maior = 1;
		vertex.clear(); sum = 0;
		t++;

		for(int i=1;i<N;++i)
			for(int j=1;j<N;++j)
				dist[i][j] = (i == j) ? 0 : INF;
		while(1)
		{
			cin>>a>>b;
			if(a+b == 0)
			{
				if(flag) return 0;

				flag = true;
				break;
			}
			else
				flag = false;
			dist[a][b] = 1;
			vertex.insert(a);
			vertex.insert(b);
			maior = max({a,b,maior});
		}		

		qnt = vertex.size();
		for(int k=1;k<N;++k)
			for(int i=1;i<N;++i)
				for(int j=1;j<N;++j)
					dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
		
		for(auto e : vertex)
			pontos.pb(e);

		for(int u = 0;u<qnt;++u)
		{
			int k = pontos[u];
			for(int i=1;i<=maior;++i)
				if(dist[k][i] != INF)
					sum+=dist[k][i];
		}

		qnt = qnt*(qnt-1);
		cout<<"Case "<<t<<": average length between pages = ";
		cout<<fixed<<setprecision(3);
		cout<<double(sum)/qnt<<" clicks\n";
	}
}