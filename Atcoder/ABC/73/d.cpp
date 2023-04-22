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

const int N = 202;
const int inf = 1e9;

int dist[N][N];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m, r;
    cin>>n>>m>>r;

    vi cities(r);
    for(auto &x : cities)
    	cin>>x;

    for(int i=0;i<=n;++i)
    	for(int j=0;j<=n;++j)
    		dist[i][j] = inf;


    for(int i=0;i<m;++i) {
    	int x, y, c;
    	cin>>x>>y>>c;
    	dist[x][y] = dist[y][x] = c;
    }

    for(int k=1;k<=n;++k)
    	for(int i=1;i<=n;++i)
    		for(int j=1;j<=n;++j)
    			dist[i][j] = min(dist[i][j],
    				dist[i][k] + dist[k][j]);

    ll best = 2e17;
    sort(all(cities));
   	do {
   		int last = cities[0];
   		ll curr = 0;
   		for(int i=1;i<r;++i) {
   			curr += dist[last][cities[i]];
   			last = cities[i];
   		}
   		best = min(best, curr);
   	}while(next_permutation(all(cities)));

   	cout<<best<<endl;
}