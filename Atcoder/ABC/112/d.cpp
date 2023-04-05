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
    ios_base::sync_with_stdio(0); cin.tie(0);
    //M = k.(x)


    ll n, m;
    cin>>n>>m;

    // K.div = m / div
    // sum(vi) = K | sz(v) = n 
    // se n > K impossivel
    // n == k , vi = 1
    // n < K, da sim

    auto possible = [&](ll divisor) {
    	return n <= m/divisor;
    };

    ll ans = 1;
    for(ll div=1;div*div<=m;++div) {
    	if(m%div == 0) {
    		if(possible(div))
    			ans = max(ans, div);
    		if(m/div != div && possible(m/div))
    			ans = max(ans, m/div);
    	}
    }

    cout<<ans<<"\n";
}