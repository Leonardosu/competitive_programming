#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int mod = 1000000007;
inline ll poww(ll a, ll b){ll res = 1;while (b > 0){if(b & 1) res = (res * a)%mod;a = (a * a)%mod;b >>= 1;}return res;}
const int N = 1e5 + 7;

int lv[N];
vector<int> g[N];

void dfs(int x)
{
	for(int &y : g[x])
		if(lv[y] == -1)
			lv[y] = lv[x] + 1,dfs(y);
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(lv,-1,sizeof(lv));

	int n,q;
	cin>>n>>q;
	for(int i=1;i<n;++i)
	{
		int x,y;
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}

	lv[0] = 0;
	dfs(0);


	while(q--)
	{
		int x,y;
		ll k;
		cin>>x>>y>>k;

		ll lenCiclo = abs(lv[x] - lv[y]) + 1;
		
		//ciclo com tamanho X com K cores
		//(K-1)^X + ( (-1)^X )*(K-1)

		ll ans = (poww(k-1,lenCiclo) + (lenCiclo&1 ? -1LL : 1LL)*(k-1) )%mod;
		//ans pode ficar negativo !!a
		if(ans < 0LL)
			ans += mod;
		
		//ans = ciclo * foraCiclo
		ans = (ans*poww(k-1,n - lenCiclo))%mod;
		cout<<ans<<"\n";		
	}

}
