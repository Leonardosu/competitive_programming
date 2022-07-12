#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n, hp;
	cin>>n>>hp;

	vector<pii> katanas(n);

	ll dps = 0;

	for(auto &[x,y] : katanas) {
		cin>>x>>y;		
		dps = max(dps, x);
	}

	sort(ALL(katanas), [](pii &a, pii &b) {
		return a.s > b.s;
	});

	
	ll throws = 0, atks = 0;
	for(int i=0;i<n;++i) {
		if(katanas[i].s > dps && hp > 0) {
			hp -= katanas[i].s;
			throws++;
		}
	}

	if(hp > 0LL) {
		atks = (hp + dps - 1LL)/dps;
	}

	cout<<atks + throws<<"\n";
}
