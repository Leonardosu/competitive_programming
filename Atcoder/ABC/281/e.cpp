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

    ll n, m, k;
    cin>>n>>m>>k;

    ll v[n];
    for(int i=0;i<n;++i)
    	cin>>v[i];

    multiset<ll> caras(v,v+m);
    auto last = next(caras.begin(), k-1);
    ll sum = accumulate(caras.begin(), next(caras.begin(), k), 0LL);
    cout<<sum<<" ";

    for(int i=0;i<n-m;++i) {
    	caras.insert(v[i+m]);
    	if (v[i+m] <= *last) sum += v[i+m] - *(last--);
    	if (v[i] <= *last) sum += *(++last) - v[i];

    	caras.erase(caras.find(v[i]));
    	cout<<sum<<" ";
    }
}