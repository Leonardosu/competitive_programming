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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	const ll a = 1000, b = 5000, c = 10000;
	
	ll n, k;
	cin>>n>>k;

	for(ll x=0; x <= n; ++x) {
		for(ll y=0; x + y <= n;++y) {
			ll resto = (k - x*a - y*b);
			if(resto%c != 0) continue;

			ll z = resto/c;
			if(x + y + z == n && x*a + y*b + z*c == k) {
				cout<<z<<" "<<y<<" "<<x<<"\n";
				return 0;
			}
		}
	}

	cout<<"-1 -1 -1\n";
}