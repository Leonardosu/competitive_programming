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
	int n;
	cin>>n;
	
	int dp[2][n];
	for(int i=0;i<2;++i)
		for(int j=0;j<n;++j)
			cin>>dp[i][j];
	for(int i=0;i<2;++i){
		for(int j=0;j<n;++j){
			int best = 0;
			if(i)
				best = dp[i-1][j];
			if(j)
				best = max(best, dp[i][j-1]);
			dp[i][j] += best;
		}
	}
	// int grid[2][n];
	cout<<dp[1][n-1]<<"\n";
}