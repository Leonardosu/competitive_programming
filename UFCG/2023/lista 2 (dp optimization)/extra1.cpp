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

struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
    static const ll inf = LLONG_MAX;
    ll div(ll a, ll b) {
        return a / b - ((a ^ b) < 0 && a % b); }
    bool isect(iterator x, iterator y) {
        if (y == end()) return x->p = inf, 0;
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,m,s,t;
    cin>>n>>m>>s>>t;
    s--, t--;

    vector<int> g[n];
    vector<ll> h(n);

    for(auto &x : h)
    	cin>>x;

    bool trivial = false;
    for(int i=0;i<m;++i) {
    	int x, y;
    	cin>>x>>y;
    	x--, y--;
    	g[x].pb(y);
    	g[y].pb(x);
    	if((x == s && y == t) || (x == t && y == s) ) {
    		trivial = true;
    	}
    }

    cout<<fixed<<setprecision(12);
    if(trivial) {
    	cout<<0.0;
    	return 0;
    }

    const ll inf = 1e16 + 100;
    auto getCost = [&](int x, int y) {
    	return (h[x] - h[y]) * (h[x] - h[y]);
    };

    auto getDist = [&](int ini) {
    	vector<ll> dist(n, inf);
    	using pii = pair<ll,ll>;

    	priority_queue<pii, vector<pii>, greater<pii>> fila;
    	dist[ini] = 0;    	
    	fila.push({0, ini});

    	while(!fila.empty()) {
    		auto [d, x] = fila.top();
    		fila.pop();
    		if(dist[x] < d) continue;

    		for(int y : g[x]) {
    			ll cost = getCost(x, y);
    			if(d + cost < dist[y]) {
    				dist[y] = d + cost;
    				fila.push({dist[y], y});
    			}
    		}
    	}
    	return dist;
    };

    vector<ll> indo = getDist(s), voltando = getDist(t);

    ll ans = -inf;
    for(int i=0;i<n;++i) {
    	LineContainer lc; 
    	//dp[i] = min(dp[j] + (h[j]-h[i])^2)
    	//			 (dp[j] + h[j]^2) - 2h[i]h[j] + h[i]^2
    	for(int x : g[i]) {
    		lc.add(2LL*h[x], -2LL*indo[x] - h[x]*h[x]);
    	}

    	if(!lc.empty()) {
	    	for(int x : g[i]) {
	    		ll res = lc.query(h[x]) - h[x]*h[x] - 2LL*voltando[x];
	    		ans = max(ans, res);
	    	}
    	}
    }

    ans *= -1LL;
    for(int x : g[s])
    	ans = min(ans, 2LL*voltando[x]);
    for(int x : g[t])
    	ans = min(ans, 2LL*indo[x]);

    cout<<0.5*ans<<"\n";
}