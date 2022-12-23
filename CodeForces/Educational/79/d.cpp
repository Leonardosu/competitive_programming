#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end();
using namespace std;

const int N = 1000010;
const int INF = 1e9;
const int MOD = 998244353;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef long long int ll;

ll inv(ll a, ll b)
{
	return 1LL < a ? b - inv(b%a,a)*b/a : 1LL;
}

ll n,k,x,ans = 1;
ll aux,cnt[N];
vector<ll> v[N];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>k;
		for(int j=1;j<=k;++j)
		{
			cin>>x;		
			v[i].pb(x);
			cnt[x]++;
		}
	}

	ans = 1;
	for(int i=1;i<=n;++i)
	{
		k = v[i].size();
		for(int j=0;j<v[i].size();++j)
		{
			x = v[i][j];
			ll now = ((cnt[x])*inv(n,MOD))%MOD;

			now = (now*inv(k,MOD))%MOD;
			now = (now*inv(n,MOD))%MOD;
			ans = (ans+now)%MOD;
		}
	}

	cout<<ans%MOD - 1<<"\n";
}