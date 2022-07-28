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
const int mod = 998244353;
ll fat[N];

int filhos[N];
vi g[N];

void dfs(int x, int pai) {
	for(int &y : g[x]) {
		if(y != pai) {
			filhos[x]++;
			dfs(y, x);
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fat[0] = fat[1] = 1;
    fat[2] = 2;
    for(int i=2;i<N;++i) 
    	fat[i] = (fat[i-1]*i)%mod;

    int n;
    cin>>n;
    for(int i=1;i<n;++i) {
    	int x, y;
    	cin>>x>>y;
    	g[x].pb(y);
    	g[y].pb(x);
    }

    dfs(1, 0);
    ll ans = (fat[filhos[1]]*n)%mod;
    for(int i=2;i<=n;++i) {
    	ans = (ans * fat[filhos[i] + 1])%mod;
    }
    cout<<ans<<"\n";
}