#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
const int N = 1e5 + 7;
const int M = 110;
const int MOD = 1e9 + 7;
typedef long long int ll;

ll dp[M][N];
int v[N];
int n,m;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	for(int i=0;i<M;++i)
		for(int j=0;j<N;++j)
			dp[i][j] = 0;

	cin>>n>>m;

	for(int i=1;i<=n;++i)
		cin>>v[i];
	
	dp[v[1]][1] = 1;
	if(v[1] == 0)
	{
		for(int i=1;i<=m;++i)
		{
			dp[i][1] = 1;
		}		
	}
	

	for(int i=2;i<=n;++i)
	{
		int x = v[i];
		int a = 1,b = m;

		if(x == 0)
		{
			for(int j=1;j<=m;++j)
				for(int k=j-1;k<=j+1;++k)
				{
					if(1<=k && k<=m)
						dp[j][i] = (dp[j][i] + dp[k][i-1])%MOD;
				}			
		}
		else
		{
			for(int k=x-1;k<=x+1;++k)
				{
					if(1<=k && k<=m)
						dp[x][i] = (dp[x][i] + dp[k][i-1])%MOD;
				}
		}
	}

	ll ans = 0;	

	for(int i=1;i<=m;++i)
		ans = (ans + dp[i][n])%MOD;

	cout<<ans<<"\n";
}