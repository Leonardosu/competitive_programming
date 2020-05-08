#include <bits/stdc++.h> //Recursive DP
#define all(x) x.begin(),x.end()
using namespace std;
const int N = 5010;
typedef long long int ll;
 
int n,x,v[N];
ll dp[N][N],sum[N];
 
ll solve(int i,int j)
{
	if(i == j) return dp[i][j] = v[i];
	if(dp[i][j] != -1) return dp[i][j];
 
	ll ans = sum[j] - sum[i-1] - min(solve(i+1,j),solve(i,j-1));
	return dp[i][j] = ans;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			dp[i][j] = -1;
 
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>v[i];
		sum[i] = sum[i-1] + v[i]; //prefix
	}
 
	cout<<solve(1,n)<<"\n";
}