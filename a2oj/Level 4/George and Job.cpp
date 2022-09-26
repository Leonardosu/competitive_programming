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

int n, m, k;
const int N = 5e3 + 7;
ll v[N], dp[N][N];
ll prefix[N];

const ll inf = -1e16;

ll soma(int l, int r) {
	return prefix[r] - prefix[l-1];
}

ll solve(int i, int k) {
	if(i > n || k < 0) {
		return (k == 0 ? 0 : inf);
	}
	
	ll &now = dp[i][k];
	if(now != -1)
		return now;

	return now = max(solve(i+1, k), 
		soma(i, i + m - 1) + solve(i+m, k-1));
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp, -1,sizeof dp);

	cin>>n>>m>>k;
	for(int i=1;i<=n;++i)
		cin>>v[i];
	prefix[0] = 0;
	for(int i=1;i<=n;++i)
		prefix[i] = prefix[i-1] + v[i];

	cout<<solve(1, k)<<"\n";
}