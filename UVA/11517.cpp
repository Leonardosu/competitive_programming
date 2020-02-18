#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 20010;
vector<int> c;
int sum,dp[N],n;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	dp[0] = 0;

	cin>>t;	
	while(t--)
	{
		cin>>sum>>n;
		c.resize(n);
		for(int i=0;i<n;++i) cin>>c[i];
		for(int i=1;i<N;++i) dp[i] = INF;

		for(auto e : c)
			for(int i = N - e - 1;i>=0;--i)
				dp[i+e] = min(dp[i+e],dp[i] + 1);

		int ans = INF,pos;
		for(int i=sum;i<N;++i)
			if(dp[i] != INF)
			{
				pos = i;
				ans = dp[i];
				break;
			}
		cout<<pos<<" "<<ans<<"\n";
	}
}