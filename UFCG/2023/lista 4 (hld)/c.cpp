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

const int N = 2e5 + 10;
const int maxn = 2e6;
struct segtree {
	struct node {
		int val;
		node(int val=0) : val(val){}
	};

	int n;
	vector<node> tree;
    segtree(int n) : n(n) { tree.resize(4*(n)); }

    void update(int no, int ini, int fim, int pos, int val) {
    	if(ini == fim) {
    		tree[no] = node(val);
    	} else {
    		int mid = (ini+fim)>>1;
    		int w = no<<1;
    		if(pos <= mid) update(w, ini, mid, pos, val);
    		else update(w+1, mid+1, fim, pos, val);
    		tree[no].val = max(tree[w].val, tree[w+1].val);
    	}
    }

    int query(int no, int ini, int fim, int l, int r) {
    	if(r < ini || fim < l) return 0;
    	if(l<=ini && fim<=r) return tree[no].val;
    	int mid = (ini+fim)>>1;
    	return max(query(2*no, ini, mid, l, r),
    			query(2*no+1, mid+1, fim, l, r));
    }    

    void update(int pos, int val) {update(1, 0, n-1, pos, val);}
    int query(int l, int r) {return query(1, 0, n-1, l, r);}
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
	inline void update(int u, int v, int val) {		
		if(par[v] == u) swap(u, v);		
		tree->update(pos[u], val);
	}
	int queryPath(int u, int v) { // Modify depending on problem
		int res = 0;
		process(u, v, [&](int l, int r) {
				res = max(res, tree->query(l, r));
		});
		return res;
	}
};

void solve_task() {
	int n;
    cin>>n;
    vector<vi> adj(n);
    vector<array<int,3>> edges;

    for(int i=1;i<n;++i) {
    	int x, y, c;
    	cin>>x>>y>>c;
    	x--, y--;
    	if(x > y) swap(x, y);

    	adj[x].pb(y);
    	adj[y].pb(x);
    	edges.pb({x, y, c});
    }

    HLD<true> hld(adj);
    for(auto [x, y, c] : edges) {
    	hld.update(x, y, c);
    }

	while(true) {		
		string t;
		cin>>t;
		if(t[0] == 'C') {
			int x, val;
			cin>>x>>val;
			x--;

			hld.update(edges[x][0], edges[x][1], val);
		} else if(t[0] == 'Q'){
			int x, y;
			cin>>x>>y;
			x--, y--;
			cout<<hld.queryPath(x, y)<<" ";
		} else {
			break;
		}
	}

	cout<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}