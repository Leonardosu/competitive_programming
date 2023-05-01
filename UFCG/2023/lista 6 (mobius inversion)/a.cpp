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
typedef vector<int> 	vi;

const int N = 60;
int mobius[N];

void init() {
	for(int i=1;i<N;++i) {
		mobius[i] = (i == 1) - mobius[i];
		for(int j=i;(j+=i)<N;)
			mobius[j] += mobius[i];
	}
}

ll kRoot(ll k, ll x, ll &upper) {
	ll lower = 1;
	while(lower < upper) {
		ll mid = (lower + upper + 1)>>1LL;
		ll val = 1;

		for(int i=0;i<k;++i) {
			if(x/mid < val) { //overflow
				val = x + 1;
				break;
			}
			val *= mid;
		}

		if(val <= x) {
			lower = mid;
		} else {
			upper = mid - 1;
		}
	}

	return upper - 1;
}

void solve_task() {
	ll n;
	cin>>n;

	ll ans = n-1;
	ll upper = 1e9;	
	for(int i=2;i<N;++i) 
		ans += kRoot(i, n, upper) * mobius[i];

	cout<<ans<<endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    double timing = clock();
    init();

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
    
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}