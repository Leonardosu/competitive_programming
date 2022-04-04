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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n,k;
	cin>>n>>k;
	vi a(n), b(n);
	for(int &x : a)
		cin>>x;
	for(int &x : b)
		cin>>x;

	bool dp[2][n];
	memset(dp, 0,sizeof(dp));
	dp[0][0] = dp[1][0] = true;

	bool can = true;

	int last = a[0];
	for(int i=1;i<n;++i)
	{
		int x = a[i], y = b[i];

		dp[0][i] = ( 
			(abs(x - a[i-1])<=k && dp[0][i-1]) ||
			(abs(x - b[i-1])<=k && dp[1][i-1])	);

		dp[1][i] = ( 
			(abs(y - a[i-1])<=k && dp[0][i-1]) ||
			(abs(y - b[i-1])<=k && dp[1][i-1])	);

		if(!dp[0][i] && !dp[1][i])
		{
			can = false;
			break;
		}
	}

	cout<<(can ? "Yes" : "No")<<"\n";
}