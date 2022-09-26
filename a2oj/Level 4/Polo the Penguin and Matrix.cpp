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

    int n, m, d;

    cin>>n>>m>>d;

    vi v;
    for(int i=0;i<n;++i)
    	for(int j=0;j<m;++j) {
    		int x;
    		cin>>x;
    		v.pb(x);
    	}

    sort(ALL(v));
    ll moves = 0;
    int target = v[v.size()/2];

    for(int x : v) {
    	ll k = (target - x)/d;
    	// x + k.d = target

    	if (x + k*d != target) {
    		moves = -1;
    		break;
    	} else {
    		moves += abs(k);
    	}
    }

	cout<<moves<<"\n";
}