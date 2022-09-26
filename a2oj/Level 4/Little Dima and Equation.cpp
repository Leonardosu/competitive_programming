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


int sum(int x) {
	int s = 0;
	while(x > 0) {
		s += x%10;
		x/=10;
	}
	return s;
}
inline ll poww(ll a, ll b){ll res = 1LL;while (b > 0LL){if(b & 1) res = (res * a);a = (a * a);b >>= 1;}return res;} 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll a, b, c;
	// x = b.s(x)^a + c
	cin>>a>>b>>c;

	vector<int> ans;
	const int limit = 1e9;
	for(ll s=1;s<=81;++s) {
		ll x = b * poww(s, a) + c;
		if(0 < x && x < limit && sum(x) == s)
			ans.pb(x);
	}

	cout<<ans.size()<<"\n";
	for(int x : ans)
		cout<<x<<" ";
}