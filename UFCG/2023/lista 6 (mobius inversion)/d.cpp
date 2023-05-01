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

const int N = 2e5 + 7;
ll v[N];
ll mobius[N];
vector<ll> divs[N];

void init() {
	for(int i=1;i<N;++i) {
		mobius[i] = (i == 1 ? 0 : 1) - mobius[i];
		for(int j=i;(j+=i)<N;)
			mobius[j] += mobius[i];
	}

	for(int i=1;i<N;++i) 
		if(mobius[i]) {
			for(int j=i;j<N;j+=i)
				divs[j].pb(i);
		}
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    double timing = clock();
    init();
    
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    	cin>>v[i];    

    ll ans = 0;
    for(int i=1;i<=n;++i) {
		map<ll,ll> freq;
		for(ll j=i;j<N;j+=i) {
			for(ll x : divs[v[j]])
				freq[x]++;
		}

		for(auto [x, cnt] : freq)
			ans += mobius[i] * mobius[x] * (cnt * (cnt+1)/2);
		// ans += f(i); //pairs j<=i that gcd(i,j) != 1 and gcd(v[i],v[j]) != 1
	}
    

    cout<<ans<<endl;
    //--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}