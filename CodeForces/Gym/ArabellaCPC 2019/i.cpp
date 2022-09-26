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
	/*

	*/
	int n;
	cin>>n;

	vector<ll> v(n);
	for(ll &x : v)
		cin>>x;
	sort(ALL(v));

	int l = 0, r = n - 1;
	ll ans = 0, sum = 0;
	
	for(int len=2;len<=n;++len) {
		if(len%2 == 0)
			sum += v[r--] - v[l++];
		ans += sum;
		cout<<ans;
		if(len != n)
			cout<<" ";
	}

}