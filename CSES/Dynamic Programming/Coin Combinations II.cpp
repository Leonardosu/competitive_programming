#include <bits/stdc++.h>
using namespace std;
const int N = 110;
const int M = 1e6 + 7;
const int MOD = 1e9 + 7;

int dp[N][M];
int coin[N];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(dp,0,sizeof(dp));
	int n,k;

	cin>>n>>k;
	for(int i=1;i<=n;++i)
		cin>>coin[i];	

	dp[0][0] = 1;

	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=k;++j)
		{
			dp[i][j] = dp[i-1][j];
			int x = j - coin[i];
			if(x >= 0)
				dp[i][j] = (dp[i][j] + dp[i][x])%MOD;
		}
	}

	cout<<dp[n][k]<<"\n";
}