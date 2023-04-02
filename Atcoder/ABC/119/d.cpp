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

    int n, m, q;
    cin>>n>>m>>q;
    vector<ll> A(n), B(m);

    for(auto &x : A)
    	cin>>x;

    for(auto &x : B)
    	cin>>x;

    const ll inf = 1e12;
    A.pb(-inf);
    B.pb(-inf);
    A.pb(inf);
    B.pb(inf);
    sort(ALL(A)); sort(ALL(B));

    auto cost = [&](ll x, vector<ll> &a, vector<ll> &b) {
    	ll cost = inf;
    	int d1 = upper_bound(ALL(a), x) - a.begin();
        ll s[2] = {a[d1-1], a[d1]};

        for(int i=0;i<2;++i) {
            ll pos = s[i];
            int d2 = upper_bound(ALL(b), pos) - b.begin();
            cost = min(cost, 
                abs(x-pos) + min(abs(b[d2] - pos),abs(b[d2-1]-pos)));
        }
    	return cost;
    };

    while(q--) {
    	ll x;
    	cin>>x;
    	// x -> a -> b
    	// x -> b -> a

    	cout<<min(cost(x, A, B), cost(x, B, A))<<"\n";
    }
}