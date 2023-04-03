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

struct point {   
    ll x, y;    
	int id;    
    point(ll x=0,ll y=0, int id=0) : x(x), y(y), id(id){}
};

ll dist(const point &a, const point &b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}
bool cmp_y(const point &a, const point &b) {
	return a.y < b.y;
}

ll minDist = LLONG_MAX;
pii best;
void upd(const point &a, const point &b) {
	ll curr = dist(a, b);
	if(curr < minDist) {
		minDist = curr;
		best = {a.id, b.id};
	}
}

vector<point> p, tmp;
void solve(int l, int r) {
	if(r - l <= 3) {
		for(int i=l;i<r;++i) 
			for(int j=i+1;j<r;++j)
				upd(p[i], p[j]);
		sort(p.begin() + l, p.begin() + r, cmp_y);
		return;
	}

	int mid = (l + r)/2;
	int midx = p[mid].x;

	solve(l, mid);
	solve(mid, r);

	merge(p.begin() + l, p.begin() + mid, 
			p.begin() + mid, p.begin() + r, 
				tmp.begin(), cmp_y);
    copy(tmp.begin(), tmp.begin() + r - l, p.begin() + l);

    int tsz = 0;
    for (int i = l; i < r; ++i) {
        if (abs(p[i].x - midx) < minDist) {
            for (int j = tsz - 1; j >= 0 && p[i].y - tmp[j].y < minDist; --j)
            	upd(p[i], tmp[j]);
            tmp[tsz++] = p[i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    for(int i=0;i<n;++i) {
    	int x, y;
    	cin>>x>>y;
    	p.pb({x, y, i});
    }
    
    sort(ALL(p), [&](const point &a, const point &b){
    	if(a.x == b.x) return a.y < b.y;
    	return a.x < b.x;
    });

    tmp.resize(n);
    solve(0, n);
    cout<<minDist<<"\n";
    cout<<best.f<<" "<<best.s<<"\n";
}