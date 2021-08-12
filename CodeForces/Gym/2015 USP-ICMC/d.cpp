#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
vi v;

int solve(vi &dp,int i)
{
	if(i >= n) return 0;
	if(dp[i] != -1) return dp[i];

	//nao pega e pega
	int best = max(solve(dp,i+1), solve(dp,i+3) + v[i]);
	return dp[i] = best;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n;
	vi dp(n,-1);
	v.resize(n);

	for(int i=0;i<n;++i)
		cin>>v[i];

	cout<<solve(dp,0)<<"\n";	
}
