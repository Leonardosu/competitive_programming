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
typedef vector<ll> vi;

map<int,vector<int>> mods;
ll n, m;

struct UnionFind {
    vector<int> parent, level;
    UnionFind(int numberNodes) {
        parent.resize(numberNodes + 1);
        level.resize(numberNodes + 1);
        for(int i=0;i<=numberNodes;++i)
            parent[i] = i, level[i] = 0;            
    }
    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void join(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(level[x] < level[y]) swap(x,y);
        if(level[x] == level[y]) level[x]++;
        parent[y] = x;
    }
};

ll mod;
inline ll poww(ll a, ll b){ll res = 1LL;while (b > 0LL){if(b & 1) res = (res * a)%mod;a = (a * a)%mod;b >>= 1;}return res;}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    vi v(n);
    mod = m;

    for(auto &x : v) {
    	cin>>x;
    }

    vector<pair<ll, pii>> edges;

    for(int i=0;i<n;++i) {
    	for(int j=i+1;j<n;++j) {
    		ll x = v[i], y = v[j];
    		int cost = (poww(x, y) + poww(y, x))%m;
    		edges.pb({-cost, {i,j}});
    	}
    }

    UnionFind uf = UnionFind(n);
    ll ans = 0;
    sort(ALL(edges));
    for(auto &q : edges) {
    	ll cost = -q.f;
    	int x = q.s.f, y = q.s.s;

    	if(uf.find(x) != uf.find(y)) {
    		ans += cost;
    		uf.join(x, y);
    	}
    }

    cout<<ans<<"\n";
}