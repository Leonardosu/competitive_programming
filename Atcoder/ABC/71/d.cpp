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
    double timing = clock();
    
    int n;
    cin>>n;

    string a, b;
    cin>>a>>b;
    vi tipos;
    for(int i=0;i<n;++i) {
    	if(a[i] == b[i]) { //vertical
    		tipos.pb(1);
    	} else {
    		tipos.pb(-1);
    		i++;
    	}
    }

    const int mod = 1e9 + 7;
	ll ans = (tipos[0] == 1 ? 3 : 6);
    for(int i=1;i<sz(tipos);++i) {
    	if(tipos[i-1] == 1)
    		ans = (ans * 2)%mod;
    	else if (tipos[i] == -1){
    		ans = (ans * 3)%mod;
    	}
    }

    cout<<ans<<endl;
    //--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}