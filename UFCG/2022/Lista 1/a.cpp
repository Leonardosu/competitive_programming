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

const int N = 5e4 + 7;
const int K = 507;
ll dp[N][K], dist[N];
vector<int> g[N];
ll n, k, ans;

void dfs(int x, int pai) {
	dp[x][0] = 1;
	for(int &y : g[x]) {
		if(y == pai) continue;
		dfs(y, x);

		for(int d=k-1;d>=0;--d) {
			ans += dp[x][d] * dp[y][k-1-d];
			dp[x][d+1] += dp[y][d];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>k;

	for(int i=1;i<n;++i) {
		int x, y;
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}

	dfs(1, -1);
	cout<<ans<<"\n";
}