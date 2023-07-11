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
mt19937 rng((ll) std::chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e5+5;
vector<pair<int,ll>> adj[N];
ll dist[N];

void dfs(int x, int p) {
	for(auto [y,c]:adj[x]) {
		if(y!=p) {
			dist[y]=dist[x]+c;
			dfs(y,x);
		}
	}
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    double timing = clock();
    
    int n;
    cin>>n;
    for(int i=1;i<n;++i) {
    	int x,y,c;
    	cin>>x>>y>>c;
    	adj[x].pb({y,c});
    	adj[y].pb({x,c});
    }

    int q,k;
    cin>>q>>k;

    dfs(k,-1);
    while(q--) {
    	int x, y;
    	cin>>x>>y;
    	cout<<dist[x]+dist[y]<<endl;
    }
    //--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}