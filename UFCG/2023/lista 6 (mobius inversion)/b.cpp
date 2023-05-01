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

const int N = 2e6 + 6;
const int mod = 1e9 + 7;
inline ll poww(ll a, ll b){ll res = 1LL;while (b > 0LL){if(b & 1) res = (res * a)%mod;a = (a * a)%mod;b >>= 1;}return res;}

ll n, k;
ll mobius[N];
ll pot[N], dp[N];

void init() {
	for(int i=1;i<N;++i) {
		mobius[i] = (i == 1 ? 1 : 0) - mobius[i];
		for(int j=i;(j+=i)<N;)
			mobius[j] += mobius[i];

		pot[i] = poww(i, n);
	}
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    double timing = clock();
    
    cin>>n>>k;
    init();
    pot[0] = 0;

    ll ans = 0;
    ll total = 0;
    for(int i=1;i<=k;++i) {
    	for(int j=i;j<=k;j+=i) {    
    		dp[j] -= pot[(j-1)/i] * mobius[i];
    		dp[j] = (dp[j] + pot[j/i] * mobius[i] + mod)%mod;
    	}

    	total = (total + dp[i])%mod;
    	ans = (ans + (total^i))%mod;
    }

    cout<<ans<<endl;
    //--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}