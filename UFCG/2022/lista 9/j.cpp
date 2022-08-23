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

const int N = 1e5 + 7;
vector<pii> g[N];
int dist[N];

void dijkstra(int s, int n) {
	fill(dist, dist + n, INT_MAX);
	dist[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({0, s});

	while(!q.empty()) {
		auto [currDist, x] = q.top(); q.pop();
		if(currDist > dist[x]) 
			continue;

		for(auto &[y, w] : g[x]) {
			if(dist[x] + w < dist[y]) {
				dist[y] = dist[x] + w;
				q.push({dist[y], y});
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m, k, source;
	cin>>n>>m>>source;
	source--;

	for(int i=0;i<m;++i) {
		int x, y, w;
		cin>>x>>y>>w; x--, y--;
		g[x].pb({y, w});
		g[y].pb({x, w});
	}

	dijkstra(source, n);
	cin>>k;

	int ans = 0;
	for(int i=0;i<n;++i) {
		if(dist[i] == k)
			ans++;
	}

	for(int i=0;i<n;++i) {
		for(auto &[j, w] : g[i]) {
			if(i > j) continue;
			if (k > dist[i] && k < dist[i] + w && w + dist[i] - k + dist[j] >= k) ++ans;
      		if (k > dist[j] && k < dist[j] + w && w + dist[j] - k + dist[i] > k) ++ans;
		}
	}

	cout<<ans<<"\n";
}