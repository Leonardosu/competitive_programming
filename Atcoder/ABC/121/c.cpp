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


    ll n, m;
    cin>>n>>m;
    vector<pair<ll,ll>> v(n);

    ll cost = 0;
    for(int i=0;i<n;++i) {
    	cin>>v[i].f>>v[i].s;
    }
    sort(v.begin(), v.end());
    int i = 0;
    while(m > 0) {
    	ll qnt = min(m, v[i].s);
    	cost += qnt * v[i].f;
    	m -= qnt;
    	i++;
    }
    cout<<cost<<"\n";
}