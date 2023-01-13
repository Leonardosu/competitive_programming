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

    ll n, k, d;
    cin>>n>>k>>d;
    ll v[n+1];
    for(int i=0;i<n;++i)
    	cin>>v[i];

    ll dp[n+1][k+2][d+1];
    memset(dp, -1, sizeof dp);
    dp[0][0][0] = 0;

	for(int i=0;i<n;++i) {
		for(int j=0;j<=k;++j) {
			for(int resto=0;resto<d;++resto) {
				if(dp[i][j][resto] == -1) continue;
				ll &curr = dp[i+1][j][resto];

				curr = max(curr, dp[i][j][resto]);
				if(j < k){
					int novo_resto = (resto + v[i])%d;
					dp[i+1][j+1][novo_resto] = max(dp[i+1][j+1][novo_resto], dp[i][j][resto] + v[i]);
				}
			}
		}
	}
 
 	cout<<dp[n][k][0]<<"\n";
}