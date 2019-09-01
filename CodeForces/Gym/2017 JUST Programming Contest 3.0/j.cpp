#include <bits/stdc++.h>
#define N 1010
using namespace std;
 
int dp[N][N],prefix[N],card[N];
int q,n;
 
int sum(int a,int b)
{
	return prefix[b] - prefix[a-1];
}
 
void init()
{
	memset(dp,-1,sizeof(dp));
	prefix[0] = 0;
	for(int i=1;i<=n;++i)
		prefix[i] = prefix[i-1] + card[i];
}
 
int solve(int i,int j)
{
	if(dp[i][j] != -1) return dp[i][j];
	if(i == j) return dp[i][j] = card[i];
	return dp[i][j] = sum(i,j) - min(solve(i+1,j) , solve(i,j-1));
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
 
	cin>>q;
	while(q--)
	{
		cin>>n;
		for(int i=1;i<=n;++i)
			cin>>card[i];
 
		init();
 
		int play1 = solve(1,n);
		int play2 = sum(1,n) - play1;
		cout<<play1 - play2<<"\n";
	}
}