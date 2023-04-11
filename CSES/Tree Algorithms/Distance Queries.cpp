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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, q;
    cin>>n>>q;
    vector<vector<int>> adj(n+1);

    for(int i=1;i<n;++i) {
    	int x, y;
    	cin>>x>>y;
    	adj[x].pb(y);
    	adj[y].pb(x);
    }

    LCA lca(n, adj, 1);

    while(q--) {
    	int x, y;
    	cin>>x>>y;
    	cout<<lca.dist(x, y)<<"\n";
    }
}