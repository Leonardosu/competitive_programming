#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;


template<class T>
struct Point{
	typedef Point P;
	T x, y;
	explicit Point(T xx =0 , T yx = 0) : x(xx) , y(yx){}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
};

typedef Point<ll> P;


vector<P> convexHull(vector<P> pts){
	if(sz(pts) <=1) return pts;
	P pivot = pts[0];
	for(int i = 0 ; i < sz(pts) ; i++) pivot = min(pivot, pts[i]);
	sort(pts.begin() , pts.end(), [&](P a , P b){
		a = a - pivot , b = b - pivot;
		int hp1 = a < P(0,0) , hp2 = b < P(0,0);
		if(hp1 != hp2) return hp1 < hp2;
		if(a.cross(b) != 0) return a.cross(b) > 0;
		return a.dist2() < b.dist2();
	});
	vector<P> hull;
	for(int i = 0 ; i < pts.size() ; i ++){
		while(hull.size() > 1 && ((hull.back() - hull[sz(hull) - 2]).cross(pts[i] - hull.back()) <= 0)) hull.pop_back();
		hull.push_back(pts[i]);
	}
	if(hull.back() == hull[0]) hull.pop_back();
	return hull;
}

template<class T>
T polygonArea2(vector<Point<T>> & v){
	T a = v.back().cross(v[0]);
	for(int i = 0 ; i < v.size() - 1 ;i ++) a += v[i].cross(v[i+1]);
	return a;	
}

ll largestAreaQuad(vector<P> v , vector<P> v2){
	if(v.size() < 3){
		return 0;
	}
	if(v.size() == 3){
		ll best = 0 ;
		int n = v2.size();
		vector<int> f(v.size());
		set<int> jf;
		for(int i = 0 ; i < v.size(); i ++){
			for(int j = 0 ; j  < v2.size(); j++){
				if(v2[j] == v[i] && !jf.count(j)){
					jf.insert(j);
					break ; 
				}
			}
		}
		for(int i = 0 ;i < n; i ++){
			if(jf.count(i)) continue;
			ll tudo = polygonArea2(v);
			ll op1 = abs(v2[i].cross(v[0],v[1]));
			ll op2 = abs(v2[i].cross(v[0],v[2]));
			ll op3 = abs(v2[i].cross(v[1],v[2]));
			best = max(best,tudo - min({op1,op2,op3}));
		}
		return best;
	}
	int n = v.size();
	ll best =0 ;
	for(int i = 0 ; i < n; i++){
		int j = (i+2)%n;
		int l = (i+1)%n;
		int r = (i+3)%n;
		auto next = [&](int j){
			if((j+1) >= n) return j + 1 - n;
			return j+1;
		};
		auto area = [&](int i , int j , int k){
			return abs(v[k].cross(v[i],v[j]));
		};
		while(i!=j){
			while(next(l) != j && area(i,j,next(l)) >= area(i,j,l)){
				l = next(l);
			}
			while(next(r) != i && area(i,j,next(r)) >= area(i,j,r)){
				r = next(r);
			}
			best = max(best , area(i,j,l) + area(i,j,r));
			j = next(j);
		}
	}
	return best;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<P> v(n);
		for(int i = 0 ; i< n; i++){
			cin >> v[i].x >> v[i].y;
		}
		ll fx = largestAreaQuad(convexHull(v) , v);
		if(fx&1) cout << fx/2 <<".5" <<endl;
		else cout << fx/2 << endl;
	}
}