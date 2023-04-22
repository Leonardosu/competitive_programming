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

        dfs(root, 0, 1);
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

struct node {
    node *l = this, *r = this;
    int val = 0;
};

node* update(node *curr, int ini, int fim, int pos, int v) {
    node *root = new node();
    if(ini == fim) {
        root->val = curr->val + v;
    } else {
        int mid = (ini+fim)>>1;
        if(pos <= mid) {
            root->l = update(curr->l, ini, mid, pos, v);
            root->r = curr->r;
        } else {
            root->l = curr->l;
            root->r = update(curr->r, mid+1, fim, pos, v);
        }
        root->val = root->l->val + root->r->val;
    }

    return root;
}

int query(node *x, node *y, node *lca, node*lca_p, 
	int ini, int fim, int k) {
	if(ini == fim) return ini;
	int left = x->l->val + y->l->val 
				- (lca->l->val + lca_p->l->val);

    int mid = (ini+fim)>>1;
    if(left >= k)
    	return query(x->l, y->l, lca->l, lca_p->l,
    				ini, mid, k);
    return query(x->r, y->r, lca->r, lca_p->r,
    				mid+1, fim, k - left);
}


const int N = 100007;
vector<vector<int>> adj;
vector<node*> versoes;
int val[N], n;

void dfs(int x, int p) {
	versoes[x] = update(versoes[p], 1, n, val[x], 1);
	for(int &y : adj[x])
		if(y != p) {
			dfs(y, x);
		}
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int m;
    cin>>n>>m;
    adj.resize(n+1);
    for(int i=0;i<=n;++i)
    	versoes.pb(new node());

    vi sorted;
    for(int i=1;i<=n;++i) {
    	cin>>val[i];
    	sorted.pb(val[i]);
    }

    sort(all(sorted));
    sorted.resize(unique(all(sorted)) - (sorted).begin());
    for(int i=1;i<=n;++i) {
    	val[i] = lower_bound(all(sorted), val[i]) - sorted.begin() + 1;
    }

    for(int i=1;i<n;++i) {
    	int x, y;
    	cin>>x>>y;
    	adj[x].pb(y);
    	adj[y].pb(x);
    }

    // adj[0] = {1};
    // adj[1].pb(0);

    LCA magic(n, adj, 1);
    dfs(1, 0);

    auto &v = versoes;
    while(m--) {
    	int x, y, k;
    	cin>>x>>y>>k;

    	int lca = magic.get_lca(x, y);
    	int lca_p = magic.anc[lca][0];
    	int id = query(v[x], v[y], v[lca], v[lca_p], 1, n, k);

    	cout<<sorted[id - 1]<<"\n";
    }

}