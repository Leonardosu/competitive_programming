#include <bits/stdc++.h> // O(m*s*s)
#define x first			
#define y second
using namespace std;

const int INF = 1e9;
const int N = 400;
vector< pair<int,int> > c;

int dp[N][N];
int t,n,s;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>t;
	while(t--)
	{
		cin>>n>>s;
		c.resize(n);

		for(int i=0;i<n;++i)
			cin>>c[i].x>>c[i].y;

		for(int i=0;i<=s;++i)
			for(int j=0;j<=s;++j)
				dp[i][j] = INF;

		dp[0][0] = 0;

		for(int i=0;i<=s;++i)
			for(int j=0;j<=s;++j)
				for(auto e : c)
					if(i - e.x >= 0 && j - e.y >= 0)
						dp[i][j] = min(dp[i][j],dp[i - e.x][j - e.y] + 1);							

		int ans = INF;

		for(int i=0;i<=s;++i)
			if(i == s)
				ans = min({ans,dp[i][0],dp[0][i]});

		for(int i=0;i<=s;++i)
			for(int j=0;j<=s;++j)
				if(i*i + j*j == s*s)
					ans = min(dp[i][j],ans);

		if(ans == INF) cout<<"not possible\n";
		else cout<<ans<<"\n";
	}
}