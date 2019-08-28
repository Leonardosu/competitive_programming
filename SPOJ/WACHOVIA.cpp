#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define N 210
#define M 1010
using namespace std;
 
int q,n,kg;
int dp[N][M];
int peso[N],v[N];
 
int solve(int i,int w)
{
	if(i>n || w<=0) return 0;
	if(dp[i][w] != -1) return dp[i][w];
 
	int npega = solve(i+1,w);
 
	if(peso[i] <= w)
	{
		int pega = solve(i+1,w-peso[i]) + v[i];
		return dp[i][w] = max(npega,pega);
	}
	return dp[i][w] = npega;
}
 
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
 
	cin>>q;
	while(q--)
	{
		cin>>kg>>n;
 
		memset(dp,-1,sizeof(dp));
 
		for(int i=1;i<=n;++i)
			cin>>peso[i]>>v[i];
 
		cout<<"Hey stupid robber, you can get "<<solve(1,kg)<<".\n";
	}
} 