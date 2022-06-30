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

	int n;
	cin>>n;
	vector<pii> v(n);

	for(auto &[x, w] : v) {
		cin>>x>>w;
	}
	
	sort(ALL(v), [](pii &a, pii &b){
		return (a.f + a.s < b.f + b.s);
	});

	int last = 0, ans = 1;
	for(int i=1;i<n;++i) {
		if(v[i].f - v[i].s >= v[last].f + v[last].s)
			last = i, ans++;
	}

	cout<<ans<<"\n";
}