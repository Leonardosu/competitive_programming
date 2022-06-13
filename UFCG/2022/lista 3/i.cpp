#include "bits/stdc++.h" //Design Tutorial: Inverse the Problem
#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 2000 + 7;

int n;
int dist[N][N];
int pai[N], sum[N];
vector<pii> g[N];
bool invalid = false;

int find(int x)
{
	if(pai[x] == x) return x;
	return pai[x] = find(pai[x]);
}

typedef array<int, 3> edge;
vector<edge> edges;
void createGraph()
{
	for(int i=1;i<=n;++i)	
		if(dist[i][i] != 0)
		{
			invalid = true;
			return;
		}

    for(int i=1;i<=n;++i)
    	for(int j=i+1;j<=n;++j)
    	{
    		if(dist[i][j] != dist[j][i] || dist[i][j] == 0)
    			invalid = true;
    		edges.pb({dist[i][j], i, j});
    	}
    
    for(int i=1;i<=n;++i)
    	pai[i] = i;

    sort(ALL(edges));    
}

void dfs(int x, int pai, int s){
	sum[x] = s;
	for(auto &[y, d] : g[x])
	{
		if(y == pai) continue;
		dfs(y, x, s + d);
	}
}
bool isValid()
{
	if(invalid)
		return false;

	int qnt = 0;
	for(edge &curr : edges)
	{
		int d = curr[0], x = curr[1], y = curr[2];
		if(find(x) == find(y))
			continue;
		pai[find(y)] = find(x);
		g[x].pb({y, d});
		g[y].pb({x, d});
		qnt++;
		if(qnt >= n)
			return false;
	}

	if(qnt != n-1)
		return false;
	for(int i=1;i<=n;++i)
	{
		dfs(i, i, 0);
		for(int j=1;j<=n;++j)
			if(sum[j] != dist[i][j])
				return false;
	}
	return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n;    
    for(int i=1;i<=n;++i)
    	for(int j=1;j<=n;++j)
    		cin>>dist[i][j];
    createGraph();
    cout<<(isValid() ? "YES" : "NO")<<"\n";
}