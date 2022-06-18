#include "bits/stdc++.h" //Office Keys
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

ll n, m, target;
vector<ll> peoples, keys;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>m>>target;
	peoples.resize(n); keys.resize(m);

	for(int i=0;i<n;++i)
		cin>>peoples[i];

	for(int i=0;i<m;++i)
		cin>>keys[i];

	sort(ALL(peoples));
	sort(ALL(keys));

	ll dp[n+1][m+1];
	const ll inf = 2e18;

	for(int i=0;i<=n;++i)
		for(int j=0;j<=m;++j)
			dp[i][j] = inf;

	dp[0][0] = 0;

	for(int i=0;i<=n;++i)
		for(int j=0;j<=m;++j)
		{
			if(j)
				dp[i][j] = min(dp[i][j], dp[i][j-1]);
			if(i && j)
			{
				ll dist = abs(peoples[i-1] - keys[j-1]) + abs(keys[j-1] - target);
				dp[i][j] = min(dp[i][j], max(dp[i-1][j-1], dist));
			}
		}

	cout<<dp[n][m]<<"\n";
}