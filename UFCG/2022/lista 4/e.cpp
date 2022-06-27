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

const int N = 1e3 + 7;
const int K = 5 + 7;
int pos[K][N], dp[N];
int n, k;

int solve(int val)
{
	if(val > n) return 0;
	if(dp[val] != -1) return dp[val];

	int best = 0;
	for(int prox=1;prox<=n;++prox)
	{
		int valids = 0;
		for(int cara=1;cara<=k;++cara)
		{
			if(pos[cara][prox] > pos[cara][val])
				valids++;
		}

		if(valids == k)
			best = max(best, solve(prox)+1);
	}

	return dp[val] = best;
}

void solve_task()
{
	memset(dp, -1, sizeof dp);
	cin>>n>>k;

	for(int i=1;i<=k;++i)
	{
		int x;
		for(int j=1;j<=n;++j)
		{
			cin>>x;
			pos[i][x] = j;
		}
	}

	int best = 0;
	for(int val=1;val<=n;++val)
		best = max(best, solve(val)+1);
	cout<<best<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T_T = 1;
	// cin>>T_T;
	while(T_T--)
		solve_task();
}