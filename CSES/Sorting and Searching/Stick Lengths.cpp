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

    int n;
    cin>>n;
    int v[n];
    for(int i=0;i<n;++i) cin>>v[i];
    sort(v, v+n);
	int x = v[n/2];

	ll ans = 0;
	for(int i=0;i<n;++i) {
		ans += abs(v[i]-x);
	}
	cout<<ans<<"\n";
}