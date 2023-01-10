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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, m = 5;
    cin>>n;
    vi v;

    ll cost = 0;
    for(int i=0;i<m;++i) {
    	ll x; cin>>x;
    	v.pb(x);
    }

    for(int i=0;i<m;++i) {
    	ll x = v[i];
    	ll rounds = (n + x - 1) / x;
    	cost = max(cost,rounds);
    }

    cout<<5 + cost - 1<<"\n";
}