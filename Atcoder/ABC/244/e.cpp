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

const int N = 2007;
const ll mod = 998244353;

bool can[N][N];
ll dp[N][N][2];    
vector<int> g[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin>>n>>m;

    int k, ini, fim, x;
    cin>>k>>ini>>fim>>x;

    for(int i=1;i<=m;++i) {
    	int x, y;
    	cin>>x>>y;
    	g[x].pb(y);
    	g[y].pb(x);
    }
	
	
    dp[0][ini][0] = 1;
    for(int d=1;d<=k;++d) {
    	for(int i=1;i<=n;++i) { // vou terminar em i
			ll par = 0;
			ll impar = 0;
    		for(int &j : g[i]) {
    			par = (par + dp[d-1][j][0])%mod;
    			impar = (impar + dp[d-1][j][1])%mod;
    		}

    		if(i == x) {
    			dp[d][i][0] = impar;
    			dp[d][i][1] = par;
    		} else {
    			dp[d][i][0] = par;
    			dp[d][i][1] = impar;
    		}
    	}
    }

    cout<<dp[k][fim][0]<<"\n";
}