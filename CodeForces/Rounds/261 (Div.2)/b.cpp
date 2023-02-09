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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin>>n;
    vector<ll> v(n);
    for(auto &x : v)
    	cin>>x;
    ll small = v[0], big = v[0];
    ll a = 0, b = 0;
    for(auto x : v) {
    	if(x <= small) {
    		if(x < small) a = 0;
    		a++;
    		small = x;
    	}

    	if(x >= big) {
    		if(x > big) b = 0;
    		b++;
    		big = x;
    	}
    }
	ll ways = a * b;    
    if(small == big) {
    	ways = a * (a -1)/2LL;
    }
    cout<<big - small<<" "<<ways<<'\n';
}