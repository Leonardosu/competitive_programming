#include <bits/stdc++.h>
using namespace std;

const int N = 30010;
vector<int> c;
long long int  sum,dp[N];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	c.resize(5);
	c[0] = 1;
	c[1] = 5;
	c[2] = 10;
	c[3] = 25;
	c[4] = 50;
	dp[0] = 1;

	for(int i=1;i<=sum;++i)
		dp[i] = 0;

	for(auto e : c)
		for(int i=e;i<N;++i)
				dp[i] += dp[i-e];

	while(cin>>sum)
	{
		if(dp[sum] == 1) cout<<"There is only 1 way to produce "<<sum<<" cents change.\n";
		else cout<<"There are "<<dp[sum]<<" ways to produce "<<sum<<" cents change.\n";
	}
}