#include "bits/stdc++.h"
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


const long long int maxn = 1e9 + 100;

struct node {
    ll a,b,v;
    node *l,*r;

    node(ll a_ = 0,ll b_ = maxn,ll v_ = 0) {
        a = a_, b = b_, v = v_;
        l = r = NULL;
    }

    void upd(ll p,ll val) {
        if(p < a || p > b) return;
        if(a == b) {
            v = val;
            return;
        }

        ll mid = (a+b)>>1LL;
        if(p <= mid) {
            if(l == NULL) l = new node(a, mid,0);
            l->upd(p,val);
        } else {
            if(r == NULL) r = new node(mid + 1, b,0);
            r->upd(p,val);
        }

        v = ( (l == NULL)? 0 : l->v ) + ( (r == NULL) ? 0 : r-> v );
    }

    ll query(ll i, ll j) {
        if(i > b || j < a) return 0LL;
        if(i <= a && b <= j) return v;

        ll A = (l == NULL)? 0 : l->query(i, j);
        ll B = (r == NULL)? 0 : r->query(i, j);

        return A + B;
    }
};


template <bool VALS_EDGES> struct HLD {
	int N, tim = 0;
	vector<vi> adj;
	vi par, siz, depth, rt, pos;
	node *tree;
	HLD(vector<vi> adj_)
		: N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1), depth(N),
		  rt(N),pos(N),tree(new node(0, N)){ dfsSz(0); dfsHld(0); }
	void dfsSz(int v) {
		if (par[v] != -1) adj[v].erase(find(all(adj[v]), par[v]));
		for (int& u : adj[v]) {
			par[u] = v, depth[u] = depth[v] + 1;
			dfsSz(u);
			siz[v] += siz[u];
			if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
		}
	}
	void dfsHld(int v) {
		pos[v] = tim++;
		for (int u : adj[v]) {
			rt[u] = (u == adj[v][0] ? rt[v] : u);
			dfsHld(u);
		}
	}
	template <class B> void process(int u, int v, B op) {
		for (; rt[u] != rt[v]; v = par[rt[v]]) {
			if (depth[rt[u]] > depth[rt[v]]) swap(u, v);
			op(pos[rt[v]], pos[v]);
		}
		if (depth[u] > depth[v]) swap(u, v);
		op(pos[u] + VALS_EDGES, pos[v]);
	}

	void update(int u, int val) {
		tree->upd(pos[u], val);
	}

	ll queryPath(int u, int v) { // Modify depending on problem
		ll res = 0;
		process(u, v, [&](int l, int r) {
				res += tree->query(l, r);
		});
		return res;
	}
};


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin>>n>>m;
    vector<vi> adj(n);
    vi v(n);
    for(int &x : v)
    	cin>>x;

    for(int i=1;i<n;++i) {
    	int x, y;
    	cin>>x>>y;
    	x--, y--;
    	adj[x].pb(y);
    	adj[y].pb(x);
    }

    HLD<false> hld(adj);
	for(int i=0;i<n;++i) {
		hld.update(i, v[i]);
	}

	while(m--) {
		ll t;
		cin>>t;
		if(t == 1) {
			int x, val;
			cin>>x>>val;
			x--;

			hld.update(x, val);
		} else {
			ll x;
			cin>>x;
			x--;
			cout<<hld.queryPath(0, x)<<"\n";
		}
	}
}