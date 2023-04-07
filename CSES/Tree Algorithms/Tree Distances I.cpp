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

const int N = 2e5 + 7;
int d1[N], d2[N];
vector<int> g[N];

void dfs(int dist[], int x, int p) {
	for(int y : g[x]) {
		if(y != p ){
			dist[y] = dist[x] + 1;
			dfs(dist, y, x);
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<n;++i) {
    	int x, y;
    	cin>>x>>y;
    	g[x].pb(y);
    	g[y].pb(x);
    }

    d1[1] = 0;
    dfs(d1, 1, -1);
    int x = 1, y = 1;
    for(int i=1;i<=n;++i) {
    	if(d1[i] > d1[x])
    		x = i;
    }

    d1[x] = 0;
    dfs(d1, x, -1);
    for(int i=1;i<=n;++i) {
        if(d1[i] > d1[y])
            y = i;
    }

    d2[y] = 0;
    dfs(d2, y, -1);
    for(int i=1;i<=n;++i) {
        cout<<max(d1[i], d2[i])<<" ";
    }
}