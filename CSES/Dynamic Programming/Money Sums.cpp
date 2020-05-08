#include <bits/stdc++.h> //O(n^2.(Max_value))
using namespace std;
const int N = 110;
const int M = 100110;
const int INF = 1e9;

int n,limit;
int coin[N];


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n;
	for(int i=0;i<n;++i) cin>>coin[i];

	limit = n*1000;
	bool dp[n+2][limit+2];
	memset(dp,false,sizeof(dp));
	
	dp[0][0] = true;


	for(int i=1;i<=n;++i)
		for(int x=0;x<=limit;++x)
		{
			dp[i][x] = dp[i-1][x];
			int need = x - coin[i-1];
			if(need >= 0 && dp[i-1][need])
				dp[i][x] = true;
		}

	int cnt = 0;
	for(int i=1;i<=limit;++i)
		if(dp[n][i]) cnt++;

	cout<<cnt<<"\n";
	for(int i=1;i<=limit;++i)
		if(dp[n][i]) 
			cout<<i<<" ";
	cout<<"\n";
}