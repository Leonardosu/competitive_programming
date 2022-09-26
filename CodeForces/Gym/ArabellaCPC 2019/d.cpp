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
ll gcd (ll a, ll b) { while (b) { a %= b,swap(a, b);}return a;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n, m;
	cin>>n>>m;
	vi a(n), b(m);
	for(ll &x : a)
		cin>>x;
	for(ll &x : b)
		cin>>x;

	if(n == 1) {
		cout<<"Yes\n";
	} else {
		ll gcd1 = a[0], gcd2 = b[0];
		for(int i=1;i<n;++i)
			gcd1 = gcd(gcd1, a[i]);
		for(int i=1;i<m;++i)
			gcd2 = gcd(gcd2, b[i]);

		cout<<(gcd1%gcd2 == 0LL ? "Yes" : "No")<<"\n";
	}
}