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

    ll dp[n+1][4]; memset(dp, 0, sizeof dp);    
    ll ans[n+1];

    dp[1][0] = dp[1][1] = dp[1][2] = dp[1][3] = 1;
    dp[2][0] = dp[2][1] = dp[2][2] = dp[2][3] = 4;
    ans[0] = 0; 
    ans[1] = 4; 
    ans[2] = 16;

    const int mod = 1e9 + 7;
    for(int i=3;i<=n;++i) {
    	dp[i][0] = ans[i-1];
	    dp[i][1] = ans[i-1];
	    dp[i][2] = ans[i-1] - dp[i-2][0] + dp[i-3][2];
	    dp[i][3] = ans[i-1] - dp[i-2][0] - dp[i-2][2] - dp[i-3][0]*3;
	    ans[i] = (dp[i][0] + dp[i][1] + dp[i][2] + dp[i][3])%mod;
    }

    cout<<ans[n]<<"\n";
}