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

const ll inf = LLONG_MAX;
const int K = 1e6 + 7;
const int N = 1e3 + 7;
ll row[K], column[K];
ll grid[N][N];

void solve(ll arr[], vector<ll> v, ll k, ll p, ll len) {
	priority_queue<ll> q;
	for(ll &x : v)
		q.push(x);

	arr[0] = 0LL;
	for(int i=1;i<=k;++i) {
		ll curr = q.top(); q.pop();
		arr[i] = arr[i-1] + curr;
		q.push(curr - 1LL*len*p);
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(row, 0, sizeof row);
	memset(column, 0, sizeof column);
	ll n, m, k, p;
	cin>>n>>m>>k>>p;

	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			cin>>grid[i][j];

	//calculate row
	vector<ll> row_sums, column_sums;
	for(int i=0;i<n;++i) {
		row_sums.pb(0LL);
		for(int j=0;j<m;++j) {
			row_sums[i] += grid[i][j];
		}
	}
	//calculate column
	for(ll i=0;i<m;++i) {
		column_sums.pb(0LL);
		for(ll j=0;j<n;++j) {
			column_sums[i] += grid[j][i];
		}
	}

	solve(row, row_sums, k, p, m);
	solve(column, column_sums, k, p, n);

	ll ans = -inf;
	for(ll i=0;i<=k;++i) {
		ll curr = row[i] - 1LL*i*(k-i)*p + column[k-i];
		ans = max(ans, curr);
	}

	cout<<ans<<"\n";
	return 0;
}