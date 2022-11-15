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

inline ll poww(ll a, ll b){ll res = 1LL;while (b > 0LL){if(b & 1) res = (res * a);a = (a * a);b >>= 1;}return res;}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin>>n>>m;
    ll ans = (n-m)*100;

	double expected = 0;
	ll times = 1;
	ll div = 2;
	ll limit = 1e7;

	const double EPS = 1e-7;
	while((1900.0*times)/div > EPS) {
		limit--;
		if(limit==0) break;
		expected += (times*1900.0) / div;
		div *= 2;
	}
    
    cout<<(ans + expected*m)*(1<<m)<<"\n";
}