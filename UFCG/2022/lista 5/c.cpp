#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 2e3 + 7;
struct T{
	int a,b;
} dp[N];

int n, dp2[N], v[N];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>v[i];
		dp[i].a = dp[i].b = 1;
		for(int j=1;j<i;++j) {
			if(v[j] <= v[i])
				dp[i].a = max(dp[i].a, dp[j].a + 1);
			if(v[j] < v[i])
				dp[i].b = max(dp[i].b, dp[j].a + 1);
			else {
				int extra = (v[j] <= v[i] ? dp[j].a + 1 : 0);				
				dp[i].b = max({dp[i].b, dp[j].b + 1, extra});
			}
		}
	}

	for(int i=n;i>=1;--i) {
		dp2[i] = 1;
		for(int j=n;j>i;--j)
			if(v[i] <= v[j])
				dp2[i] = max(dp2[i], dp2[j] + 1);
	}
	
	int ans = 1;
	for(int i=n;i>=1;--i)
		ans = max(ans, dp[i].b + dp2[i] - 1);
	cout<<ans<<"\n";
}