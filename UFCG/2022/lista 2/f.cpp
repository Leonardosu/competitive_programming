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

const int N = 2e5 + 7;
ll a[N], b[N];

void solve_task()
{
	ll n, c;
	cin>>n>>c;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<n;++i)
		cin>>b[i];

	ll days = 0, curr = 0;
	ll ans = 1e18;

	for(int i=1;i<=n;++i) {
		ans = min(ans, days + max(0ll, c - curr + a[i] - 1) / a[i]);

		ll daysToWait = max(0LL, (b[i] - curr + (a[i]-1))/a[i]);
		days += daysToWait + 1;
		curr += daysToWait * a[i] - b[i];
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