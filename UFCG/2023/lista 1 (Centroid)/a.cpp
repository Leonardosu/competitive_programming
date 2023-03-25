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

struct LCA {
    int n, lg;	
    vector<vector<int>> adj, anc;
    vector<int> h;
    int root;
    
    LCA(){}
    LCA(int n, vector<vector<int>> adj, int root) : n(n), adj(adj), root(root) {
        lg = 33 - __builtin_clz(n);
        anc = vector<vector<int>>(n + 1, vector<int>(lg));
        h.resize(n + 1);

        dfs(root, -1, 1);
        for (int i = 1; i < lg; i++) {
            for (int v = 1; v <= n; v++) {
                if (h[v] - (1 << i) >= 1) {
                    anc[v][i] = anc[anc[v][i - 1]][i - 1];
                }
            }
        }
    }

    void dfs(int v, int p, int d) {
        h[v] = d;
        for (int c : adj[v]) {
            if (c == p) continue;
            anc[c][0] = v;
            dfs(c, v, d + 1);
        }
    }

    int get_lca(int a, int b) {
        if (h[a] < h[b]) swap(a, b);

        for (int i = lg - 1; i >= 0; i--) {
            if (h[a] - h[b] >= (1 << i)) a = anc[a][i];
        }
        if (a == b) return a;

        for (int i = lg - 1; i >= 0; i--) {
            if (anc[a][i] != anc[b][i]) {
                a = anc[a][i];
                b = anc[b][i];
            }
        }
        return anc[a][0];
    }

    int dist(int a, int b) {
        return h[a] + h[b] - 2 * h[get_lca(a, b)];
    }
};

struct CentroidDecomposition {
	int n;
    vector<int> par, vis, sz;
    vector<vector<int>> adj;

    const int INF = 1e9;
    vector<int> best;
    LCA lca;

    CentroidDecomposition(vector<vector<int>> adj) : adj(adj){
    	n = adj.size();
    	par.resize(n); vis.resize(n); sz.resize(n);
    	build_cent(n - 1, -1);

    	init();
    }

    int build_sz(int x, int p) {
		sz[x] = 1;
		for(int &y : adj[x]) {
			if(!vis[y] && y != p)
				sz[x] += build_sz(y, x);			
		}
		return sz[x];
	}

	int get_centroid(int x, int p, int tam) {
		for(int &y : adj[x]) {
			if(!vis[y] && y != p && sz[y] * 2 > tam) 
				return get_centroid(y, x, tam);			
		}
		return x;
	}

    void build_cent(int v, int p) {
        build_sz(v, -1);
        int c = get_centroid(v, -1, sz[v]);
        par[c] = p;
        vis[c] = true;
        for (int ch : adj[c]) {
            if (!vis[ch]) build_cent(ch, c);
        }
    }

    void init() {
    	best.resize(n, INF);
    	lca = LCA(n, adj, 0);
    }

    void update(int x) {
    	best[x] = 0;
    	int nxt = par[x];
    	while(nxt != -1) {
    		best[nxt] = min(best[nxt], lca.dist(x, nxt));
    		nxt = par[nxt];
    	}
    }

    int query(int x) {
    	int ans = best[x];
    	int nxt = par[x];
    	while(nxt != -1) {
    		ans = min(ans, best[nxt] + lca.dist(x, nxt));
    		nxt = par[nxt];
    	}
    	return ans;
    }
};


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=1;i<n;++i) {
    	int x, y;
    	cin>>x>>y;
    	x--, y--;
    	adj[x].pb(y);
    	adj[y].pb(x);
    }

    CentroidDecomposition cd(adj);
    cd.update(0);

    while(m--) {
    	int t, x;
    	cin>>t>>x;
    	x--;

    	if(t == 1) {
    		cd.update(x);
    	} else {
    		cout<<cd.query(x)<<"\n";
    	}
    }
}