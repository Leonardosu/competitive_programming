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

const int mod = 1e9 + 7;
const int N = 1e5 + 7;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    double timing = clock();
    int q, k;
    cin>>q>>k;
    ll f[N];

    f[0] = 1;
    for(int i=1;i<N;++i) {
    	f[i] = f[i-1] + (i-k >= 0 ? f[i-k] : 0);

    	if(f[i] > mod)
    		f[i] -= mod;
    }
    
    for(int i=1;i<N;++i) {
    	f[i] = (f[i] + f[i-1])%mod;
    } 

    while(q--) {
    	int l, r;
    	cin>>l>>r;
    	ll res = f[r] - f[l-1];
    	if(res < 0) res += mod;
    	cout<<res<<endl;
    }
    //--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}