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

ll f(ll x, ll tam) {
	ll qnt = x/tam;
	ll ones = tam * (qnt / 2);
	return ones + (qnt%2 == 0 ? 0 : x%tam);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll a, b;
    cin>>a>>b;
    ll ans = 0;

    for(ll bit=0;bit<41;++bit) {
    	ll tam = 1LL << bit;
    	if((f(b+1, tam) - f(a, tam))%2 == 1) {
    		ans |= (1LL << bit);
    	}
    }

    cout<<ans<<"\n";
}	