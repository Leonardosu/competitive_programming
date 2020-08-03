#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
const int N = 1e5 + 7;
const int INF = INT_MAX;
using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

set<int> v;
set<ii> edges;
vector<int> g[N];

int n,m;

void dfs(int x)
{
	v.erase(x);
	vector<int> aux;
	for(int next : v)
		if(edges.find({x,next}) == edges.end())
			aux.pb(next);			
	
	for(int x : aux)
		v.erase(x);
	for(int x : aux)
		dfs(x);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n>>m;
	for(int i=0;i<m;++i)
	{
		int x,y;
		cin>>x>>y;
		edges.insert({x,y});
		edges.insert({y,x});
	}

	for(int i=1;i<=n;++i) v.insert(i);
	
	int cost = 0;
	for(int i = 1;i <= n;++i)
		if(v.find(i) != v.end())
		{
			cost++;
			dfs(i);
		}

	cout<<cost - 1<<"\n";
}