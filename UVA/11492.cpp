#include <bits/stdc++.h>	// O(N*(LogN)^2) {map<>}
#define f first				//Babel
#define s second
#define mp make_pair
#define pb push_back
using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;
typedef pair<int,string> T;
typedef pair<int,T> TT; //distancia,davez,ultima palavra

const int INF = 1e9;
const int N = 5015;
map<string,int> dic;
vector<T> graph[N];
int dist[N];
int qnt,n;

void go(string name)
{
	if(dic.count(name))
		return;
	dic[name] = qnt;
	qnt++;
}

int solve(string ini,string fim)
{
	for(int i=0;i<N;++i)
		dist[i] = INF;

	priority_queue<TT, vector<TT> , greater<TT> > fila;
	dist[dic[ini]] = 0;
	fila.push(mp(0,mp(dic[ini],"?")));
	int vezes = 0;

	while(!fila.empty())
	{
		int d = fila.top().f;
		int u = fila.top().s.f;
		string last = fila.top().s.s;

		fila.pop();

		if(u == dic[fim]) break;

		for(int i=0;i<graph[u].size();++i)
		{
			int xx = graph[u][i].f;
			string name = graph[u][i].s;

			if((name[0] != last[0]) && dist[xx] >= d + int(name.size()))
			{
				dist[xx] = d + int(name.size());
				fila.push(mp(dist[xx],mp(xx,name)));
			}
		}
	}
	return dist[dic[fim]];
}

int main()
{
	
	while(cin>>n && n)
	{
		dic.clear(); qnt = 0;

		for(int i=0;i<n+10;++i)		
		{
			dist[i] = INF;
			graph[i].clear();
		}

		string x,y,name;
		string ini,fim;

		cin>>ini>>fim;
		for(int i=0;i<n;++i)
		{
			cin>>x>>y>>name;
			go(x); go(y);
			graph[dic[x]].pb(mp(dic[y],name));
			graph[dic[y]].pb(mp(dic[x],name));
		}

		// go(ini); go(fim);
		

		int ans = solve(fim,ini);
		if(ans == INF)
			cout<<"impossivel\n";
		else
			cout<<ans<<"\n";
	}
}