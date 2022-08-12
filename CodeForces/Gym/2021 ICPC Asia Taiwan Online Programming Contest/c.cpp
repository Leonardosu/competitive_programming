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

const ll N = 200007;
ll bit[N];
void update(ll x, ll val) {
	while(x < N) {
		bit[x] += val;
		x += x&(-x);
	}
} 

ll query(ll x) {
	ll sum = 0;
	while(x > 0) {
		sum += bit[x];
		x -= x&(-x);
	}
	return sum;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    ll v[n];

    for(ll i=1;i<=n;++i){
    	ll x;
    	cin>>x;
    	v[x] = i;
    }

    ll moves = 0;
    for(ll i=1;i<=n;++i) {
    	ll x = v[i];
    	moves += query(n) - query(x);
    	update(x, 1);
    }
    cout<<moves<<"\n";
}