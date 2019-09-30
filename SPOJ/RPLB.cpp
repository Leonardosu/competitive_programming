/*
	RPLB  SPOJ
	Leonardo Su
*/
#include <bits/stdc++.h>
#define N 1010
using namespace std;

int t,n,carry;

int value[N];
int dp[N][N];

int solve(int i,int k)
{
	if(i>n || k>carry) return 0;
	if(dp[i][k] != -1) return dp[i][k];
	int nbota = solve(i+1,k);
	if(k + value[i] <= carry)
	{
		int bota = solve(i+2,k+value[i]) + value[i];
		return dp[i][k] = max(nbota,bota);
	}
	return dp[i][k] = nbota;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>t;
	for(int z=1;z<=t;++z)
	{
		cin>>n>>carry;
		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j)
				dp[i][j] = -1;
		
		for(int i=1;i<=n;++i)
			cin>>value[i];

		cout<<"Scenario #"<<z<<": "<<solve(1,0)<<"\n";
	}

}