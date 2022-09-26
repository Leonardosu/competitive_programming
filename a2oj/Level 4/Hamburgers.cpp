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

	int n = 3;
	vector<ll> need(n);
	vector<ll> have(n), cost(n);
	string s;
	cin>>s;
	for(char c : s) {
		if(c == 'B')
			need[0]++;
		else if(c == 'S')
			need[1]++;
		else
			need[2]++;
	}

	for(int i=0;i<n;++i)
		cin>>have[i];
	for(int i=0;i<n;++i)
		cin>>cost[i];
	ll totalMoney;
	cin>>totalMoney;

	ll ans = 0;
	ll l = 0, r = 1e12 + 121;
	while(l<=r) {
		ll mid = (l + r)>>1;

		ll needMoney = 0;
		for(int i=0;i<n;++i) {
			needMoney += max(0LL, need[i]*mid - have[i]) * cost[i];
		}

		if(needMoney <= totalMoney) {
			ans = mid, l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

	cout<<ans<<"\n";
}