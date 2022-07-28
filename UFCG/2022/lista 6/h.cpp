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

const int N = 3e5 + 7;
struct edge{
	ll to, cost, id;
	edge(ll a, ll b, ll c) {
		to = a, cost = b, id = c;
	}
};

vector<ll> entrada;
vector<edge> g[N];
bool visited[N];
ll previous[N], edgeId[N];
ll dist[N];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(visited, false, sizeof visited);
	memset(previous, -1, sizeof previous);
	const ll inf = 2e18;

	ll n, m, source;
	cin>>n>>m;
	for(int i=0;i<=n;++i)
		dist[i] = inf;

	for(int i=1;i<=m;++i) {
		ll x, y, w;
		cin>>x>>y>>w;

		entrada.pb(w);
		g[x].pb(edge(y, w, i));
		g[y].pb(edge(x, w, i));
	}

	cin>>source;
	dist[source] = 0;

	priority_queue<pii, vector<pii>, greater<pii>> fila;

	// priority_queue<pii> fila;
	fila.push({0, source});
	ll sum = 0;
	while(!fila.empty()) {
		auto [d, x] = fila.top(); fila.pop();

		if(visited[x]) continue;
		visited[x] = true;

		for(auto &nxt : g[x]) {
			ll y = nxt.to;
			ll cost = d + nxt.cost;
			if(cost < dist[y]) {
				previous[y] = x;
				edgeId[y] = nxt.id;

				dist[y] = d + nxt.cost;
				fila.push({dist[y], y});
			} else if(cost == dist[y] && nxt.cost < entrada[edgeId[y]-1]) {
				previous[y] = x;
				edgeId[y] = nxt.id;
			}
		}
	}

	vector<ll> edges;
	memset(visited, false, sizeof visited);
	for(int i=1;i<=n;++i) 
		if(previous[i] != -1 && !visited[i]) {

			int curr = i;
			while(curr != source && !visited[curr]) {
				visited[curr] = true;
				edges.pb(edgeId[curr]);
				sum += entrada[edgeId[curr]-1];
				curr = previous[curr];
			} 
		}


	cout<<sum<<"\n";
	for(ll &x : edges){
		cout<<x<<" ";
	}
}