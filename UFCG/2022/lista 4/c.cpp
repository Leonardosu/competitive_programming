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

const int N = 5000 + 7;
int dp[N][N], v[N];
int n;

int solve(int i=0, int j=0) {
	if(i == n+1)
		return 0;
	if(~dp[i][j])
		return dp[i][j];
	dp[i][j] = min(solve(i+1, (v[i]>=v[j] ? j : i)) + 1,
					solve(i+1, i) + max(v[i]-v[j], 0));
	return dp[i][j];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    memset(dp, -1, sizeof dp);
    cin>>n;

    for(int i=1;i<=n;++i)
    	cin>>v[i];

    cout<<solve()<<"\n";
}