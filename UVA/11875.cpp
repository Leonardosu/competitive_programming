#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

vector<int> v;
int t,n,x;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin>>t;
	for(int j=1;j<=t;++j) {
		cin>>n;
		for(int i=0;i<n;++i) {
			cin>>x;
			v.pb(x);
		}

		sort(v.begin(),v.end());

		cout<<"Case "<<j<<": "<<v[n/2]<<"\n";
		v.clear();
	}
}