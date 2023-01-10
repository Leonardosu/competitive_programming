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
typedef vector<ll> vi;

bool cmp(ll x, ll y) {
	return x > y;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int A, B, C, K;
	cin>>A>>B>>C>>K;
	vi a(A), b(B), c(C);
	for(ll &value : a) cin>>value;
	for(ll &value : b) cin>>value;
	for(ll &value : c) cin>>value;

	sort(ALL(a), cmp);
	sort(ALL(b), cmp);
	sort(ALL(c), cmp);

	vi ans;
	priority_queue<pair<ll, array<int,3>>> fila;
	set<array<int,3>> vis;

	fila.push({a[0]+b[0]+c[0], {0,0,0}});
	while(!fila.empty()) {
		ll val = fila.top().f;
		auto ids = fila.top().s;
		fila.pop();
		if(present(vis, ids)) continue;
		vis.insert(ids);

		cout<<val<<"\n";
		K--;
		if(K == 0) break;

		if(ids[0] + 1 < A) {
			ids[0]++;
			val = a[ids[0]] + b[ids[1]] + c[ids[2]];
			fila.push({val, ids});
			ids[0]--;
		}

		if(ids[1] + 1 < B) {
			ids[1]++;
			val = a[ids[0]] + b[ids[1]] + c[ids[2]];
			fila.push({val, ids});
			ids[1]--;
		}

		if(ids[2] + 1 < C) {
			ids[2]++;
			val = a[ids[0]] + b[ids[1]] + c[ids[2]];
			fila.push({val, ids});
			ids[2]--;
		}
	}


}