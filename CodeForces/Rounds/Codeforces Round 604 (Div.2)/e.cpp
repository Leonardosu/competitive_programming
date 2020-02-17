#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define debug(x) cout<<"\n### _("<<x<<")_###\n";
using namespace std;

const int N = 2e5 + 7;
const int INF = 1e9;
const int MOD = 998244353;
typedef long long int ll;
typedef pair<int,int> ii;

int n;
ll dp[N];

ll mult(ll x,ll y)
{	return (x*y)%MOD; }

ll poww(ll x,ll y)
{
	ll z = 1;
	while(y > 0)
	{
		if(y%2 == 1) z = mult(z,x);
		x = mult(x,x);
		y/=2;
	}
	return z%MOD;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>dp[i];

	dp[0] = 0;
	for(int i=1;i<=n;++i)
		dp[i] = mult( ((dp[i-1] + 1LL)*100)%MOD , poww(dp[i],MOD - 2) );

	cout<<dp[n]<<"\n";
}