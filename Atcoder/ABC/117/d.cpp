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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    ll k;
    cin>>n>>k;
    ll v[n];
    for(int i=0;i<n;++i) {
    	cin>>v[i];
    }

    ll num = 0;
    for(int bit=41;bit>=0;--bit) {
    	ll big = (1LL<<bit);
    	if(big > k) continue;

    	ll a = 0, b = 0; //a = ligo o bit, b = n ligo
    	for(int i=0;i<n;++i) {
    		if(v[i]&big) { // ta ligado
    			b += big;
    		} else {
    			a += big;
    		}
    	}

    	if((num|big) <= k && a > b) {
    		num |= big;
    	}
    }

    ll ans = 0;
    for(int i=0;i<n;++i) {
    	ans += v[i]^num;
    }
    
    cout<<ans<<"\n";
}