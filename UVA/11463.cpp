#include <bits/stdc++.h> //O(N^3)
using namespace std;	// Floyd-Warshall

const int N = 128;
const int INF = 1e9;
int t,n,m,q,S,E;
int dp[N][N];
int a,b;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>t;
	for(int zz=1;zz<=t;++zz)
	{
		cin>>n>>m;
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				dp[i][j] = (i == j) ? 0 : INF;

		for(int i=0;i<m;++i)
		{
			cin>>a>>b;
			dp[a][b] = 1;
			dp[b][a] = 1;			
		}

		cin>>S>>E;
		int ans = 0;
		for(int k=0;k<n;++k)
			for(int i=0;i<n;++i)
				for(int j=0;j<n;++j)
					dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]);

		for(int i=0;i<n;++i)
			ans = max(ans,dp[S][i] + dp[i][E]);
		
		cout<<"Case "<<zz<<": "<<ans<<"\n";
	}
}