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
	int N;
	vector<ll> bit;
	BIT(int n){
		N = n+2;
		bit.resize(N);
	}

	void update(int x, int val) {
		while(x < N)
			bit[x] += val, x += x&-x;		
	}

	void update(int L, int R, int val) {
		update(L, val);
		update(R+1, -val);
	}

	ll query(int x) {
		ll sum = 0;
		while(x > 0)
			sum += bit[x], x -= x&-x;
		return sum;
	}	
};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin>>n;

	vector<ll> s(n);	
	vi a(n);

	for(ll &x : s)
		cin>>x;

	BIT bit = BIT(n);
	for(int i=1;i<=n;++i)
		bit.update(i, i); 
	for(int i=n-1;i>=0;--i) {
		int l = 1, r = n;
		while(l != r) {
			int mid = (l + r + 1)/2;
			ll sum = bit.query(mid - 1);
			if(sum > s[i])
				r = mid - 1;
			else
				l = mid;
		}
		a[i] = r;
		bit.update(a[i], -a[i]);
	}

	for(int &x : a)
		cout<<x<<" ";
	
	cout<<"\n";
}