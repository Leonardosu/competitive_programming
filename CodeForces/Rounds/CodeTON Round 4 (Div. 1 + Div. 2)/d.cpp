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

struct interval {
	ll l, r;

 	void setRange(ll left, ll right) {
		l = left, r = right;
    }
    
    bool queryRange(ll left, ll right) {
    	return !(right < l || left > r);
    }
    
    void reduceRange(ll left, ll right) {
    	if(queryRange(left, right)) {    
	    	l = max(left, l);
	    	r = min(r, right);
    	}
    }
};

void solve_task() {
	int q;
	cin>>q;
	interval data;
	data.setRange(1, 1e18);

	auto cost = [](ll a, ll b, ll h) {
		return (h - b - 1LL) / (a - b) + 1LL;
	};

	while(q--) {
		int t;
		cin>>t;
		ll a, b, n;

		if(t == 1) { //update de range
			cin>>a>>b>>n;
			ll l = (a-b)*(n-2) + a + 1LL;
			ll r = (a-b)*(n-1) + a;
			if(n == 1) l = 1LL, r = a;

			data.reduceRange(l, r);
			cout<<(data.queryRange(l, r) ? 1 : 0)<<" ";
		} else {
			cin>>a>>b;
			ll minC = max(1LL, cost(a, b, data.l));
			ll maxC = max(1LL, cost(a, b, data.r));

			cout<<(maxC == minC ? maxC : -1)<<" ";
		}
	}

	cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}