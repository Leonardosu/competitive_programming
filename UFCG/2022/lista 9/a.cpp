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

    ll a, b, q;
    cin>>a>>b>>q;
    const int inf = 1e6 + 7;
    while(q--) {
    	ll l, t, m;
    	cin>>l>>t>>m;

    	ll lo = l, hi = inf;
    	ll ans = -1;
    	while(lo <= hi) {
    		ll mid = (lo + hi)>>1LL;
    		ll f1 = a + (l - 1)*b;
    		ll len = (mid - l + 1);

    		ll curr = f1 * len + len * (len - 1LL) * b / 2LL;

    		if(a + b * (mid - 1LL) > t || curr > m*t) {
    			hi = mid -1;
    		} else {
    			ans = mid;
    			lo = mid + 1;
    		}
    	}

    	cout<<ans<<"\n";
    }
}