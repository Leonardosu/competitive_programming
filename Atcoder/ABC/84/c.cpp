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
	vi c(n), s(n), f(n);
	for(int i=0;i<n-1;++i)
		cin>>c[i]>>s[i]>>f[i];

	for(int i=0;i<n-1;++i) {
		ll cost = 0;
		for(int j=i;j<n-1;++j) {
			if(cost < s[j])
				cost += s[j] - cost;
			else {
				// k >= cost / f[j]
				ll k = (cost + f[j] - 1)/f[j];
				cost += k*f[j] - cost;
			}

			cost += c[j];
		}
		cout<<cost<<"\n";
	}
	cout<<"0\n";
}