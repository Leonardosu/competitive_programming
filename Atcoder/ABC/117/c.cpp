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

    int n, m;
    cin>>n>>m;

    vi v(m);
    for(auto &x : v)
    	cin>>x;

    if(n == m) {
    	cout<<"0\n";
    	return 0;
    }

    sort(ALL(v));
    vi diff;
    for(int i=1;i<m;++i) {
    	diff.pb(v[i] - v[i-1]);
    }
    
    sort(diff.rbegin(), diff.rend());
    ll ans = 0;
    n--;
    for(int i=0;i<sz(diff);++i) {
    	if(n) {
    		n--;
    		continue;
    	} else {
    		ans += diff[i];
    	}

    }

    cout<<ans<<"\n";
}