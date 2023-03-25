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
    vector<ll> freq;
    int limit;
    ll ans;

    CentroidDecomposition(vector<vector<int>> adj, int limit) : adj(adj), limit(limit){
        n = adj.size();
        par.resize(n); vis.resize(n); sz.resize(n);

        ans = 0;
        freq.resize(limit + 1, 0);
        build_cent(0);
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

    void update(int x, int p, int d, int t) {
        if(d < limit) {
            freq[d] += t;
            for(int y : adj[x]) {
                if(!vis[y] && y != p) 
                    update(y, x, d + 1, t);
            }
        }
    }

    void query(int x, int p, int d) {
        if(d == limit) {
            ans ++;            
        } else {
            ans += freq[limit - d];
            for(int y : adj[x]) {
                if(!vis[y] && y != p)
                    query(y, x, d + 1);
            }
        }        
    }

    void build_cent(int v) {
        build_sz(v, -1);
        int c = get_centroid(v, -1, sz[v]);
        
        for(int &y : adj[c]) {
            if(!vis[y])
                update(y, c, 1, 1);
        }

        for(int &y : adj[c]) {
            if(!vis[y]) {
                update(y, c, 1, -1);
                query(y, c, 1);
            }
        }

        vis[c] = true;
        for (int ch : adj[c]) {
            if (!vis[ch]) build_cent(ch);
        }
    }

};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k;
    cin>>n>>k;
    vector<vector<int>> adj(n);
    for(int i=1;i<n;++i) {
    	int x, y;
    	cin>>x>>y;
    	x--,y--;
    	adj[x].pb(y);
    	adj[y].pb(x);
    }

    CentroidDecomposition cd(adj, k);
    cout<<cd.ans<<"\n";
}