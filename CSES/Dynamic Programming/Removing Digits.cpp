#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 1e6;
const int INF = 1e9;
 
 
typedef long long int ll;
int dp[N];
 
 
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	for(int i=0;i<N;++i) dp[i] = INF;
	int n;
	cin>>n;
	dp[0] = 0;
 
	for(int x = 0;x<=n;++x)
	{
		for(char c : to_string(x))
		{
			dp[x] = min(dp[x],dp[x-(c-'0')] + 1);			
		}
		
	}
 
	cout<<dp[n]<<"\n";
}