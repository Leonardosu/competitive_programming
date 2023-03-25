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
    vector<int> vis, sz;
    vector<vector<int>> adj;
    vector<int> val;
    const static int M = 28;
    int freq[M][2];
    ll ans = 0;

    CentroidDecomposition(vector<vector<int>> adj, vector<int> val) : adj(adj), val(val) {
        n = adj.size();
        vis.resize(n); sz.resize(n);
        
        memset(freq, 0, sizeof freq);
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
    int qnt = 0;

    void update(int x, int p, int now) {
        for(int bit=0;bit<M;++bit) {
            ((now & (1<<bit)) ? freq[bit][1] : freq[bit][0]) += 1;
        }

        for(int y : adj[x]) {
            if(!vis[y] && y != p) 
                update(y, x, now ^ val[y]);
        }
    }

    void query(int pivot, int x, int p, int now) {        
        now ^= val[pivot];
        for(int bit=0;bit<M;++bit) {
            ll toAdd = 1LL << bit;
            if(now & toAdd) {
                toAdd *= freq[bit][0] + 1;            
            } else {
                toAdd *= freq[bit][1];
            }

            ans += toAdd;
        }
        now ^= val[pivot];

        for(int y : adj[x]) {
            if(!vis[y] && y != p)
                query(pivot, y, x, now ^ val[y]);
        }
    }

    void build_cent(int v) {
        build_sz(v, -1);
        int c = get_centroid(v, -1, sz[v]);
        
        memset(freq, 0, sizeof freq);

        for(int &y : adj[c]) {
            if(!vis[y]) {
                query(c, y, c, val[y]);
                update(y, c, val[y]);
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

    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    vector<int> val(n);
    ll total = 0;
    for(int &x : val)  {
        cin>>x;
        total += x;
    }

    for(int i=1;i<n;++i) {
        int x, y;
        cin>>x>>y;
        x--,y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    CentroidDecomposition cd(adj, val);
    cout<<cd.ans + total<<"\n";
}
