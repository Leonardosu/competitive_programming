#include <bits/stdc++.h>
using namespace std;
const int N = 510;
const int INF = 1e9;

int dp[N][N];
int n,m;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


	cin>>n>>m;

	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			if(i == j) dp[i][j] = 0;
			else
			{
				dp[i][j] = INF;
				for(int a=1;a<i;++a)
					dp[i][j] = min(dp[i][j],dp[a][j] + dp[i-a][j] + 1);

				for(int b=1;b<j;++b)
					dp[i][j] = min(dp[i][j],dp[i][b] + dp[i][j-b] + 1);
			}
		}
	
	cout<<dp[n][m]<<"\n";
}