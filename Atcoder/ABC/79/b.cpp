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

	ll n;
	cin>>n;
	ll f[n+1];
	f[0] = 2;
	f[1] = 1;

	for(ll i=2;i<=n;++i)
		f[i] = f[i-1] + f[i-2];

	cout<<f[n]<<"\n";
}