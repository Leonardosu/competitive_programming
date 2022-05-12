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

struct BIT{
	ll N;
	vector<ll> A;
	BIT(ll M) : N(M), A(M+1, 0) {}
 
    void add(ll i, ll x) {
        for (ll k = i; k <= N; k += (k & -k)) A[k] += x;
    }
 
    ll sum(ll i) {
        ll sum = 0;
        for (ll k = i; k > 0; k -= (k & -k)) sum += A[k];
        return sum;
    }
};

vector<pii> monsters;
int n, k, damage;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>n>>k>>damage;
	monsters.resize(n);
	for(auto &monster : monsters)
		cin>>monster.f>>monster.s;

	sort(ALL(monsters));
	vector<ll> x(n);
	for(int i=0;i<n;++i)
		x[i] = monsters[i].f;

	BIT bit(n);
	ll ans = 0;
	for(int i=0;i<n;++i)
	{
		ll sum = monsters[i].s - (damage * bit.sum(i+1));
		if(sum > 0)
		{
			ll num = (sum + damage - 1) / damage;
			bit.add(i + 1, num);
			ll pos = upper_bound(ALL(x), monsters[i].f + 2LL*k) - x.begin();
			bit.add(pos + 1, -num);
			ans += num;
		}
	}
	cout<<ans<<"\n";
}