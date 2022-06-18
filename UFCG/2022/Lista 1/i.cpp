#include "bits/stdc++.h" //Flood Fill
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

const int N = 5e3 + 7;
const int inf = 1e9;
int v[N], dp[N][N], k;
vector<int> vals;

int solve(int l, int r)
{
	if(l == 0 && r == k - 1)
		return 0;

	if(dp[l][r] != -1)
		return dp[l][r];

	if(0 < l && r+1 < k && vals[l-1] == vals[r + 1])
		return dp[l][r] = solve(l-1,r+1) + 1;

	int left =  (0 < l ? solve(l-1, r) : inf);
	int right = (r+1 < k ? solve(l,r+1) : inf);

	return dp[l][r] = min(left,right) + 1;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(dp, -1, sizeof dp);
	int n, best = inf;
	cin>>n;

	int last = -1;
	for(int i=1, x;i<=n;++i)
	{
		cin>>x;
		if(x != last)
			vals.pb(x);
		last = x;
	}

	// for(int &x : vals)
		// cout<<x<<" ";
	// cout<<"~\n";

	k = vals.size();
	for(int i=0;i<k;++i)
		best = min(best, solve(i,i));

	cout<<best<<"\n";
}