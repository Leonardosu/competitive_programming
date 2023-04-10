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


const ll mod = 1e9 + 7;
const int K = 9, W = 9, H = 101;
ll dp[H][W];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll h, w, k;
    cin>>h>>w>>k;
    if(w == 1) {
    	cout<<1<<"\n";
    	return 0;
    }

    auto valid = [&](int bitmask) {
    	for(int i=0;i<w-2;++i) {
    		int a = bitmask >> i;
    		int b = bitmask >> (i+1);
    		if((a&1) & (b&1)) return false;
    	}
    	return true;
    };

    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;

    for(int i=0;i<h;++i) {
    	for(int j=0;j<w;++j) {
    		for(int state=0;state<(1LL<<(w-1));++state) {
    			if(valid(state)) {
    				ll *now = &dp[i+1][j];
    				if(state & (1<<j)) {
    					now = &dp[i+1][j+1];
    				} else if(j!=0 && (state & (1<<(j-1)))) {
    					now = &dp[i+1][j-1];
    				}

    				*now = (*now + dp[i][j])%mod;
    			}
    		}
    	}
    }

    cout<<dp[h][k-1]<<"\n";
}