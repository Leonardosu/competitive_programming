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

int n;
struct pt {
	ll x, y;
	pt(ll x_ = 0, ll y_ = 0){
		x = x_, y = y_;
	}
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n;
    vector<pt> points(n);
    for(pt &p : points) {
    	cin>>p.x>>p.y;
    }
    /*
    	A ---- B
    	 \      \
    	  \      \
    	   D------C
    */
    map<pair<ll,ll>, int> cnt;
    for(int i=0;i<n;++i) { // A
    	for(int j=0;j<i;++j) { // C
    		int mx = points[i].x + points[j].x;
    		int my = points[i].y + points[j].y;
    		cnt[{mx, my}]++;
    		}
    	}

    ll ans = 0;
    for(auto &p : cnt) {
    	ans += (p.s * (p.s-1) ) / 2LL;
    }

    cout<<ans<<"\n";
}