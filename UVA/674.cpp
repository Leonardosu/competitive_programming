#include <bits/stdc++.h> // Coin change
using namespace std;

const int N = 7500;
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
	for(int i=1;i<N;++i)
		dp[i] = 0;

	for(auto e : c)
		for(int i=e;i<N;++i)
				dp[i] += dp[i-e];

	while(cin>>sum)
		cout<<dp[sum]<<"\n";
	
}