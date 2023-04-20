#include "bits/stdc++.h"
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin>>n>>m;
 	ll dp[n+1][n+1];
	ll v[n+1];
	for(int i=1;i<=n;++i)
		cin>>v[i];    

 	ll mod = 998244353;
 	memset(dp, 0, sizeof dp);
 	dp[0][0] = 1;

	for(int i=1;i<=n;++i) {
		for(int group=1;group<=n;++group) {
			dp[i][group] = (dp[i-1][group-1] + 
						dp[i-1][group] * (group - (i-1)/m))%mod;
 		}
	}

	for(int i=1;i<=n;++i)
		cout<<dp[n][i]<<endl;
}