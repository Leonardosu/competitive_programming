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

const int N = 1e5 + 7;
vector<int> g[N];
ll dp[N], a[N], b[N];

LineContainer dfs(int x, int p) {
    LineContainer lc;

    for(int y : g[x]) {
        if(y != p) {
            LineContainer now = dfs(y, x);
            if(now.size() > lc.size()) 
                swap(lc, now);

            for(auto l : now)
                lc.add(l.k, l.m);
        }
    }

    if(!lc.empty()) {
        dp[x] = lc.query(-a[x]);
    }
    lc.add(b[x], dp[x]);
    return lc;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=0;i<n;++i)
        cin>>b[i];    

    for(int i=1;i<n;++i) {
        int x, y;
        cin>>x>>y;
        x--, y--;
        g[x].pb(y);
        g[y].pb(x);
    }

    dfs(0, -1);
    for(int i=0;i<n;++i) {
        cout<<-dp[i]<<" ";
    }
}