#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
const int maxn = 210;
const int inf = 2e9;

int n,m;
int a[maxn],b[maxn];
int ans[maxn];
vector<set<int>> g[maxn];

int dp[207][1<<10 + 7];

int get(int i,int atual)
{
	if(dp[i][atual] != -1) return dp[i][atual];
	if(i == n+1) return atual;

	int ans = 1023;

	for(int j=1;j<=m;++j)
	{
		int now = a[i]&b[j];
		now = atual|now;

		ans = min(ans,get(i+1,now));
	}

	return dp[i][atual] = ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	memset(dp,-1,sizeof(dp));
	cin>>n>>m;

	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=m;++i) cin>>b[i];

	
	cout<<get(1,0)<<"\n";
}