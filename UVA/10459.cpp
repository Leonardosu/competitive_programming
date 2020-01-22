#include <bits/stdc++.h>	// O(N*Log)
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;

const int N = 5010;
typedef pair<int,int> ii;
vector<int> graph[N],worst,best;

int t,n,maior,x,m;
int lv[N],D[N];
bool seen[N];

int main()
{

	while(cin>>n)
	{
		for(int i=1;i<=n;++i)
		{
			graph[i].clear();
			seen[i] = false,D[i] = 0;
		}

		for(int i=1;i<=n;++i)
		{
			cin>>m;
			lv[i] = m;
			for(int j=1;j<=m;++j)
			{
				cin>>x;
				graph[i].pb(x);			
			}
		}

		queue<ii> fila;
		worst.clear();
		best.clear();

		for(int i=1;i<=n;++i)
			if(lv[i] == 1)
				fila.push(mp(i,1));
			

		maior = -1;

		while(!fila.empty())
		{
			int u = fila.front().f;
			int d = fila.front().s;
			fila.pop();
			if(seen[u]) continue;

			D[u] = d;
			seen[u] = true;
			maior = max(maior,d);

			for(int i = 0;i<graph[u].size();++i)
			{
				int v = graph[u][i];
				lv[v]--;
				if(!seen[v] && lv[v] == 1)
					fila.push(mp(v,d+1));
			}
		}

		for(int i=1;i<=n;++i)
			if(D[i] == maior)
				best.pb(i);

		for(int i=0;i<best.size();++i)
		{
			queue<ii> fila;
			for(int j=1;j<=n;++j)
				seen[j] = false,D[j] = 0;

			fila.push(mp(best[i],0)); int ans = 0;

			while(!fila.empty())
			{
				int u = fila.front().f;
				int d = fila.front().s;
				fila.pop();
				if(seen[u]) continue;
				seen[u] = true;
				D[u] = d;
				ans = max(ans,d);
				for(int i=0;i<graph[u].size();++i)
				{
					int v = graph[u][i];
					if(!seen[v])
						fila.push(mp(v,d+1));			
				}
			}
			for(int i=1;i<=n;++i)
				if(D[i] == ans)
					worst.pb(i);
		}

		sort(all(worst));

		cout<<"Best Roots  : ";
		for(int i=0;i<best.size();++i)
		{
			if(i != 0) cout<<" ";
			cout<<best[i];
		}

		cout<<"\nWorst Roots : ";
		for(int i=0;i<worst.size();++i)
		{
			if(i != 0) cout<<" ";
			cout<<worst[i];
		}

		cout<<"\n";
	}

}