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

	int n, q;
	cin>>n;
	ll v[n], pref[n];
	pref[0] = 0;

	ll biggest = 0;

	for(int i=1;i<=n;++i) {
		cin>>v[i];
		pref[i] = pref[i-1] + v[i];
		biggest = max(biggest, (pref[i] + i - 1)/ i);
	}

	cin>>q;
	while(q--) {
		ll t;
		cin>>t;

		ll ans = (pref[n] + t - 1)/t;

		if(t < biggest) 
			ans = -1;
		
		cout<<ans<<"\n";
	}
}
