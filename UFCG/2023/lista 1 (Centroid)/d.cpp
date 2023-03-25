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

struct CentroidDecomposition {
    int n;
    vector<int> par, vis, sz;
    vector<vector<int>> adj;

    vector<int> h;

    CentroidDecomposition(vector<vector<int>> adj) : adj(adj){
        n = adj.size();
        par.resize(n); vis.resize(n); sz.resize(n);

        h.resize(n, -1);        
        build_cent(0, 0);
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

        h[c] = (p == -1 ? 0 : h[p] + 1);
        for (int ch : adj[c]) {
            if (!vis[ch]) build_cent(ch, c);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    for(int i=1;i<n;++i) {
    	int x, y;
    	cin>>x>>y;
    	x--,y--;
    	adj[x].pb(y);
    	adj[y].pb(x);
    }

    CentroidDecomposition cd(adj);

    for(int i=0;i<n;++i) {
    	cout<<char(cd.h[i] + 'A')<<" ";
    }
    cout<<"\n";
}