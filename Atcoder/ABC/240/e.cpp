#include "bits/stdc++.h"
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
const int N = 2e5 + 7;
vector<int> g[N];
vector<pii> ans(N);
int lv[N];
int qnt = 1;

void mark(int x, int pai)
{
	if(g[x].size() == 1 && x != 1)
		ans[x] = {qnt, qnt}, qnt++;
	else
	{
		for(auto &y : g[x])
			if(y != pai)
				mark(y, x);
	}
}

void dfs(int x, int pai)
{
	if(lv[x] != 1) 
	{
		ans[x] = {INT_MAX, INT_MIN};
		for(auto &y : g[x])
		{
			if(y != pai)
			{
				dfs(y, x);
				ans[x].f = min(ans[x].f, ans[y].f);
				ans[x].s = max(ans[x].s, ans[y].s);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin>>n;
	
	for(int i=2;i<=n;++i)
	{
		int x,y;
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
		lv[x]++, lv[y]++;
	}

	lv[1] = 3;
	mark(1, -1);
	dfs(1, -1);

	for(int i=1;i<=n;++i)
		cout<<ans[i].f<<" "<<ans[i].s<<"\n";
}