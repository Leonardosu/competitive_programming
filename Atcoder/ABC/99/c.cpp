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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// N = 3.3() 2.3

	int n;
	cin>>n;
	int dp[n+1];
	dp[0] = 0;
	for(int val=1;val<=n;++val)
	{
		dp[val] = dp[val-1] + 1; // pick 1 yen

		//using 6
		for(int k=6;val-k>=0;k*=6)
			dp[val] = min(dp[val],dp[val-k] + 1);

		for(int k=9;val-k>=0;k*=9)
			dp[val] = min(dp[val],dp[val-k] + 1);
	}

	cout<<dp[n]<<"\n";
}