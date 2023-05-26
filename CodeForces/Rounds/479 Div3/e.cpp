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

const int N = 2e5 + 7;
vector<int> g[N];
int lv[N];
bool vis[N];
vi group;

void dfs(int x, int p) {
	group.pb(x);
	vis[x] = true;
	for(int y : g[x]) {
		if(y != p && !vis[y]) {
			dfs(y, x);
		}
	}
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    double timing = clock();
    
    int n, m;
    cin>>n>>m;
    for(int i=0;i<m;++i) {
    	int x, y;
    	cin>>x>>y;
    	g[x].pb(y);
    	g[y].pb(x);
    	lv[x]++, lv[y]++;
    }

    int cycles = 0;
    for(int i=1;i<=n;++i) {
    	if(!vis[i]) {
    		group.clear();
    		dfs(i, -1);

    		bool flag = true;
    		for(int x : group) {
    			flag &= lv[x] == 2;
    		}

    		if(flag) cycles++;
    	}
    }
    cout<<cycles<<endl;
    //--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}