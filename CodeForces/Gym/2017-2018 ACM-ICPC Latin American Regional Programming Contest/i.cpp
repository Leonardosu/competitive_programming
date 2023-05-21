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


const long long int maxn = 2e6 + 100;
const int N = 2e5 + 10;
int value[N];

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
    		int mid = (ini+fim)/2;
    		int w = 2*no;
    		if(pos <= mid) update(w, ini, mid, pos, val);
    		else update(w+1, mid+1, fim, pos, val);
    		tree[no].val = max(tree[w].val, tree[w+1].val);
    	}
    }

    int query(int no, int ini, int fim, int l, int r) {
    	if(r < ini || fim < l) return 0;
    	if(l<=ini && fim<=r) return tree[no].val;
    	int mid = (ini+fim)/2;
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

struct UnionFind {
    vector<int> parent, level;
    UnionFind(int numberNodes) {
        parent.resize(numberNodes + 1);
        iota(all(parent), 0);
        level.resize(numberNodes + 1, 0);
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

ll total = 0;
map<pair<int,int>, int> cost;
vector<array<int,3>> qwe;

vector<vi> createMST(int n, vector<array<int,3>> edges) {
	UnionFind uf(n);
	sort(all(edges));1
	vector<vi> adj(n);

	for(auto [w, x, y] : edges) {
		if(uf.find(x) != uf.find(y)) {
			total += w;
			uf.join(x, y);
			adj[x].pb(y);
			adj[y].pb(x);
			qwe.pb({w, x, y});
		}
	}

	return adj;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    double timing = clock();

    int n, m;
    cin>>n>>m;

    vector<array<int,3>> edges;
    for(int i=1;i<=m;++i) {
    	int x, y, w;
    	cin>>x>>y>>w;
    	x--, y--;

    	edges.pb({w, x ,y});  

    	if(x > y) swap(x, y);
    	cost[{x, y}] = w;
    }

    HLD<true> hld(createMST(n, edges));
	for(auto [w, x, y] : qwe) {
		hld.update(x, y, w);
	}

	int q;
	cin>>q;
	while(q--) {
		int x, y;
		cin>>x>>y;
		x--, y--;
		if(x > y) swap(x, y);

		int to_remove = hld.queryPath(x, y);
		cout<<total - to_remove + cost[{x,y}]<<endl;
	}

	cout<<"\n";
	//--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}