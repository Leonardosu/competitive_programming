#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
const int N = 1010;
const int INF = 1e9;
const int MOD = 1e9 + 7;

typedef long long int ll;
typedef pair<int,int> ii;

int n;
ll dp[N][N];
bool mm[N][N];


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	memset(dp,0,sizeof(dp));

	char x;
	cin>>n;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			cin>>x;
			if(x == '.')
				mm[i][j] = true;
			else
				mm[i][j] = false;
		}

	if(mm[1][1])
		dp[1][1] = 1;
	
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(mm[i][j])
				dp[i][j] += (dp[i-1][j] + dp[i][j-1])%MOD;
			

	cout<<dp[n][n]<<"\n";
}