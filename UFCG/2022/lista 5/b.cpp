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
ll gcd (ll a, ll b) { while (b) { a %= b,swap(a, b);}return a;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n, k;
	cin>>n>>k;

	ll g = 0;
	for(int i=0;i<n;++i) {
		ll x;
		cin>>x;
		g = gcd(g, x%k);
	}

	set<ll> caras;
	for(int i=1;i<=k;++i)
		caras.insert((i * g) % k);


	cout<<caras.size()<<"\n";
	for(auto &i : caras)
			cout<<i<<" ";		
	cout<<"\n";
}