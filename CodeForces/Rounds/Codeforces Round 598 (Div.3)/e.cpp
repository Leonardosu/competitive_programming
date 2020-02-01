#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
using namespace std;

const int N = 200010;
const int INF = 1e9;
typedef long long int ll;

int n,t;

ll dp[N];
int ans[N],id[N];
vector<pair<int,int> > v;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n;
	v.resize(n);
	for(int i=0;i<n;++i)
	{
		cin>>v[i].f;
		v[i].s = i+1;
	}

	sort(v.begin(),v.end());

	for(int i=0;i<=n;++i)
		dp[i] = INF,ans[i] = - 1;
	dp[0] = 0;

	for(int i=0;i<n;i++)
	{
		for(int j=3;j<=5 && i+j<=n;++j)
		{
			int d = v[i+j-1].f - v[i].f;
			if(dp[i+j] > dp[i] + d)
			{
				dp[i+j] = dp[i] + d;
				ans[i+j] = j;
			}
		}	
	}

	int times = 1;

	for(int i=n;i>=1;--i)
	{
		int cnt = ans[i];
		for(int j=1;j<=cnt;++j)
			id[v[i-j].s] = times;
		i-=(cnt - 1);			
		times++;
	}

	cout<<dp[n]<<" "<<times-1<<"\n";
	for(int i=1;i<=n;++i)
		cout<<id[i]<<" ";

	cout<<"\n";
}