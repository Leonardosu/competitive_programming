#include "bits/stdc++.h"
#define x first
#define y second
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

    using pt = pair<ll, ll>;
    int n, k;
    cin>>n>>k;

    vector<pt> points(n);
    for(auto &p : points)
    	cin>>p.x>>p.y;

    sort(all(points)); // sort by x
    auto count = [&](pt dx, pt dy) {
    	int cnt = 0;
    	for(auto p : points) {
    		if(dx.x <= p.x && p.x <= dx.y
    			&& dy.x <= p.y && p.y <= dy.y)
    			cnt++;
    	}
    	return cnt;
    };

    auto area = [&](pt a, pt b) {
    	assert(a.x <= a.y);
    	assert(b.x <= b.y);
    	return (a.y - a.x) * (b.y - b.x);
    };

    ll ans = LLONG_MAX;
    for(int x1=0;x1<n;++x1) {
    	for(int x2=x1+1;x2<n;++x2) 
    		for(int y1=0;y1<n;++y1) 
    			for(int y2=0;y2<n;++y2) {
    				pt dx = {points[x1].x, points[x2].x};
    				pt dy = {points[y1].y, points[y2].y};

    				if(count(dx, dy) >= k)
    					ans = min(ans, area(dx, dy));
				}
	}

    cout<<ans<<endl;
}