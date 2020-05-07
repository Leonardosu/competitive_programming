#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
const int INF = 1e9;

int dp[N][N];
string a,b;
int n,m;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


	cin>>a>>b;
	n = a.size();
	m = b.size();

	for(int i=0;i<=n;++i)
		for(int j=0;j<=m;++j)
			dp[i][j] = INF;

	dp[0][0] = 0;

	for(int i=0;i<=n;++i)
		for(int j=0;j<=m;++j)
		{
			if(i) dp[i][j] = min(dp[i][j],dp[i-1][j] + 1);

			if(j) dp[i][j] = min(dp[i][j],dp[i][j-1] + 1);

			if(i && j)
			{
				if(a[i-1] == b[j-1]) dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
				else dp[i][j] = min(dp[i][j],dp[i-1][j-1] + 1);
			}
		}

	cout<<dp[n][m]<<"\n";
}