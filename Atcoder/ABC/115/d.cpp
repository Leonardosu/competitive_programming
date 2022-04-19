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

ll paty[52],len[52];

ll solve(ll n,ll x)
{
	if(n == 0)
		return (x <= 0 ? 0 : 1);
	else if(x <= 1 + len[n-1])
		return solve(n-1,x-1);
	else
		return paty[n-1] + 1 + solve(n-1,x - 2 - len[n-1]);	
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll x,n;
	cin>>n>>x;

	paty[0] = 1LL;
	len[0] = 1LL;
	for(int i=1;i<=n;++i)
	{
		paty[i] = paty[i-1]*2LL + 1LL;
		len[i] = len[i-1]*2LL + 3LL;
	}

	cout<<solve(n,x)<<"\n";
}