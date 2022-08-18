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
typedef vector<ll> vi;

const int N = 1e5 + 7;
vector<pii> g[N];
ll val[N];
bool visited[N];
bool invalid;

void dfs(int x) {
	for(auto &[y, w] : g[x]) {
		if(!visited[y]) {
			val[y] = val[x] + w;
			visited[y] = true;
			dfs(y);
		} 
		else if(val[y] - val[x] != w){
			invalid = true;
			return;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(val, -1, sizeof val);
	memset(visited, false, sizeof visited);

	int n, m;
	cin>>n>>m;
	vector<array<ll, 3>> queries;

	for(int i=0;i<m;++i) {
		ll x,y,w;
		cin>>x>>y>>w;
		
		g[x].pb({y, w});
		g[y].pb({x, -w});
		queries.pb({x, y, w});
	}

	bool valid = true;
	for(int i=1;i<=n;++i) {
		if(!visited[i]) {			
			val[i] = 0;

			invalid = false;
			dfs(i);
			if(invalid) {
				valid = false;
				break;
			}
		}
	}

	for(auto &[x, y, w] : queries) {
		if(val[y] - val[x] != w) {
			valid = false;
			break;
		}
	}

	cout<<(valid ? "Yes" : "No")<<'\n';
	return 0;
}