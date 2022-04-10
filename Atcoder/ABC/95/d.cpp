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

const int N = 1e5 + 7;
vector<array<ll,2>> v(N);
vector<ll> prefixo(N,0), sufixo(N,0);

int n;
ll c;

void init()
{
	for(int i=1;i<=n;++i)
		prefixo[i] = prefixo[i-1] + v[i][1];

	for(int i=n;i>=1;--i)
		sufixo[i] = sufixo[i+1] + v[i][1];
}

ll oneDir()
{
	ll ans = 0;
	for(int i=1;i<=n;++i)
		ans = max(ans,prefixo[i] - v[i][0]);
	for(int i=n;i>=1;--i)
		ans = max(ans,sufixo[i] - c + v[i][0]);
	return ans;	
}

ll leftToRight()
{
	ll best = 0;
	vector<ll> f(n+2,0);

	for(int i=1;i<=n;++i)
		f[i] = max(f[i-1], prefixo[i] - v[i][0]);
	for(int left=n;left>=1;--left)
	{
		int right = left - 1;
		ll curr = sufixo[left] - 2LL*(c - v[left][0]) + f[right];
		best = max(best,curr);
	}
	return best;
}

ll rightToLeft()
{
	ll best = 0;
	vector<ll> f(n+2,0);

	for(int i=n;i>=1;--i)
		f[i] = max(f[i+1], sufixo[i] - c + v[i][0]);
	for(int right=1;right<=n;++right)
	{
		int left = right + 1;
		ll curr = prefixo[right] - 2LL*(v[right][0]) + f[left];
		best = max(best,curr);
	}
	return best;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>c;
	for(int i=1;i<=n;++i)
		cin>>v[i][0]>>v[i][1];
	
	init();
	ll ans = max({oneDir(),leftToRight(),rightToLeft()});
	cout<<ans<<"\n";
}