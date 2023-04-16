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

struct segtree {
    using T = long long int;
    struct node {
        T val;
        node(T val=0) : val(val){}
    };

    int n;
    vector<node> tree;
    vector<T> lazy;
    segtree(int n) : n(n), tree(4*n), lazy(4*n) {}

    void push(int no, int l, int r) {
        T &x = lazy[no];
        if(x) {
            tree[no].val ^= x;
            if(l!=r) lazy[2*no] ^= x, lazy[2*no+1] ^= x;
            x = 0;
        }
    }

    void update(int no, int ini, int fim, int l, int r, T val) {
        push(no, ini, fim);
        if(r < ini || fim < l) return;

        if(l<=ini && fim<=r) {
            lazy[no] ^= val;
            push(no, ini, fim);         
        } else {
            int mid = (ini+fim)>>1;
            int w = no<<1;
            update(w, ini, mid, l, r, val);
            update(w+1, mid+1, fim, l, r, val);

            tree[no].val = (tree[w].val ^ tree[w+1].val);
        }
    }

    T query(int no, int ini, int fim, int l, int r) {
        push(no, ini, fim);

        if(r < ini || fim < l) return 0;
        if(l<=ini && fim<=r) return tree[no].val;
        int mid = (ini+fim)>>1;
        return (query(2*no, ini, mid, l, r) ^
                query(2*no+1, mid+1, fim, l, r));
    }    

    void update(int l, int r, T val) {update(1, 0, n-1, l, r, val);}
    T query(int l, int r) {return query(1, 0, n-1, l, r);}
};


template <bool VALS_EDGES> struct HLD {
	int N, tim = 0;
	vector<vi> adj;
	vi par, siz, depth, rt, pos;
	segtree *tree;
	HLD(vector<vi> adj_)
		: N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1), depth(N),
		  rt(N),pos(N),tree(new segtree(N)){ dfsSz(0); dfsHld(0); }
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
	ll valToUpdate;	
	void update(int u, int v, ll val) {
		valToUpdate = val;
		process(u, v, [&](int l, int r) { tree->update(l, r, valToUpdate); });
	}
	ll queryPath(int u, int v) { // Modify depending on problem
		ll res = 0;
		process(u, v, [&](int l, int r) {
				res ^= tree->query(l, r);
		});
		return res;
	}

	int dist(int u, int v) {
		int a = u, b = v;
		for (; rt[u] != rt[v]; v = par[rt[v]]) {
			if (depth[rt[u]] > depth[rt[v]]) swap(u, v);
		}
		if (depth[u] > depth[v]) swap(u, v);
		return depth[a] + depth[b] - 2*depth[u] + 1;
	}
};

const int N = 250000 + 7;
const ll limit = 1e17;
map<int, ll> value;
ll prefix_set[N];

void solve_task() {
   	int n, m;
    cin>>n>>m;
    vector<vi> adj(n);
    vector<ll> v(n);
    for(ll &x : v) {
    	cin>>x;
    	x = value[x];
    }

    for(int i=1;i<n;++i) {
    	int x, y;
    	cin>>x>>y;
    	x--, y--;
    	adj[x].pb(y);
    	adj[y].pb(x);
    }

    HLD<false> hld(adj);    
    for(int i=0;i<n;++i) {
    	hld.update(i, i, v[i]);
    }

	while(m--) {		
		int t, x, y;
		cin>>t>>x>>y;
		x--, y--;
		if(t == 1) {
			ll set_value = hld.queryPath(x, y);
			int dist = hld.dist(x, y);
			cout<<(prefix_set[dist] == set_value ? "Yes" : "No")<<"\n";
		} else {
			hld.update(x, x, v[x]);
			v[x] = value[y+1];
			hld.update(x, x, v[x]);
		}
	}
	
}
void precalc() {
	uniform_int_distribution<ll> dist;
    mt19937 rng((ll) std::chrono::steady_clock::now().time_since_epoch().count());

    set<ll> caras;
    for(int i=1;i<N;++i) {
    	value[i] = dist(rng);
    	prefix_set[i] = prefix_set[i-1] ^ value[i];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    precalc();
    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}