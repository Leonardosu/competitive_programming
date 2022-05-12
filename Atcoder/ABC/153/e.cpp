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


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int h, n;
	cin>>h>>n;

	vector<pii> v(n);
	int maior = 0;
	for(auto &x : v)
	{
		cin>>x.f>>x.s;
		maior = max(maior, x.f);
	}

	int limit = h + maior;
	int dp[limit+1];
	const int inf = 2e9;
	for(int i=0;i<=limit;++i)
		dp[i] = inf;

	dp[0] = 0;
	int ans = inf;
	for(int w=0;w<=limit;++w)
	{
		for(auto &spell : v)
			if(spell.f <= w)
				dp[w] = min(dp[w], dp[w-spell.f] + spell.s);

		if(w >= h)
			ans = min(ans, dp[w]);
	}

	cout<<ans<<"\n";
}