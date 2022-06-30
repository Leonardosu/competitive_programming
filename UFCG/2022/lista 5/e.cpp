#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

const int N = 1e5 + 7;
vector<int> g[N];
ll balance[N];
pii ans;

pii dfs(int x, int parent) {
	pii curr = {0,0};

	for(int &y : g[x]) {
		if(y == parent) continue;

		pii nxt = dfs(y, x);
		curr.f = max(curr.f, nxt.f);
		curr.s = max(curr.s, nxt.s);
	}

	balance[x] -= curr.f - curr.s;
	if(balance[x] > 0)
		curr.f += balance[x];
	else
		curr.s -= balance[x];
	return curr;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin>>n;
	for(int i=1;i<n;++i) {
		int x, y;
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
	
	for(int i=1;i<=n;++i)
		cin>>balance[i];

	pii ans = dfs(1, -1);
	cout<<ans.f + ans.s<<"\n";
}	