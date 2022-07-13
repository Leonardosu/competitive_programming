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

const int n = 6;
vector<ll> c(6);

void solve_task()
{
	ll x, y;
	cin>>x>>y;
	for(int i=0;i<n;++i)
		cin>>c[i];

	swap(x,y);
	ll ans = 0;

	ans += (x <= 0 ? -c[4] : c[1]) * x;
	ans += (y <= 0 ? -c[2] : c[5]) * y;

	if(x >= 0) {
		ll curr = c[0] * x;
		ll delta = y - x;

		ll a = c[5] * delta, b = -c[2] * delta;
		if(delta > 0)
			ans = min(ans, curr + a);
		else if (delta < 0)
			ans = min(ans, curr + b);
		else
			ans = min({ans, curr + a, curr + b});
	}

	if(y >= 0) {
		ll curr = c[0] * y;
		ll delta = x - y;

		ll a = c[1] * delta, b = - c[4] * delta;
		if(delta > 0)
			ans = min(ans, curr + a);
		else if (delta < 0)
			ans = min(ans, curr + b);
		else
			ans = min({ans, curr + a, curr + b});
	}

	if(x <= 0) {
		ll curr = -c[3] * x;
		ll delta = y - x;

		ll a = c[5] * delta, b = -c[2] * delta;
		if(delta > 0)
			ans = min(ans, curr + a);
		else if(delta < 0)
			ans = min(ans, curr + b);
		else
			ans = min({ans, curr + a, curr + b});
	}

	if(y <= 0) {
		ll curr = -c[3] * y;
		ll delta = x - y;

		ll a = c[1] * delta, b = -c[4] * delta;
		if(delta > 0)
			ans = min(ans, curr + a);
		else if(delta < 0)
			ans = min(ans, curr + b);
		else
			ans = min({ans, curr + a, curr + b});
	}

	cout<<ans<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T_T = 1;
	cin>>T_T;
	while(T_T--)
		solve_task();
}