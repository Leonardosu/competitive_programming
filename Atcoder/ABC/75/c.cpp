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

const int N = 52;
bool can[N][N];
bool vis[N];
int n, m;

void dfs(int x) {
	vis[x] = true;

	for(int y=1;y<=n;++y)
		if(x != y && can[x][y] && !vis[y]) {
			vis[y] = true;
			dfs(y);
		}
}

bool isBridge(int x, int y) {
	can[x][y] = can[y][x] = false;
	memset(vis, false, sizeof vis);

	vis[x] = true;
	dfs(x);

	int cnt = 0;
	for(int i=1;i<=n;++i)
		if(vis[i])
			cnt++;

	can[x][y] = can[y][x] = true;
	return cnt != n;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin>>n>>m;
    vector<pii> edges;
    for(int i=0;i<m;++i) {
    	int x, y;
    	cin>>x>>y;
    	can[x][y] = can[y][x] = true;
    	edges.pb({x, y});
    }

    int cnt = 0;
    for(auto [x, y] : edges) {
    	cnt += (isBridge(x, y));
    }

    cout<<cnt<<endl;
}