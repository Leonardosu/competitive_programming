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

const int N = 207;
int n;
vi g[N];
vector<pii> edges;
bool can[N][N];
int dist[N];

pii longestPath(int x) {
	
}

int diametro(int x) {
	pii state = longestPath(x);
	state = longestPath(state.first);

	return state.second;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=1;i<n;++i) {
    	int x, y;
    	cin>>x>>y;
    	can[x][y] = can[y][x] = true;
    	g[x].pb(y);
    	g[y].pb(x);
    	edges.pb({x,y});
    }

    int ans = 0;
   	for(auto &[x, y] : edges) {
   		// cout<<"# "<<x<<" : "<<y<<"\n";
   		can[x][y] = can[y][x] = false;
		ans = max(ans, diametro(x)*diametro(y));
		can[x][y] = can[y][x] = true;
   	}
   	cout<<ans<<"\n";
}