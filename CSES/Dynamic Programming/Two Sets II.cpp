#include <bits/stdc++.h>
using namespace std;
const int N = 510;
const int M = 125300;
const int MOD = 1e9 + 7;

int dp[N][M];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	memset(dp,0,sizeof(dp));

	int n,limit;
	cin>>n;
	limit = (n*(n+1))/2;

	if(limit&1)
	{
		cout<<"0\n";
		return 0;
	}

	limit/=2;
	dp[0][0] = 1;

	for(int i=1;i<n;++i)
		for(int j=0;j<=limit;++j)
		{
			dp[i][j] = dp[i-1][j];
			int x = j - i;
			if(x >= 0)
				dp[i][j] = (dp[i][j] + dp[i-1][x])%MOD;
		}
	cout<<dp[n-1][limit]<<"\n";
}