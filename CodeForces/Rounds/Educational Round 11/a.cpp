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
	vi v(n);
	for(int &x : v)
		cin>>x;    

	vi ans;
	int moves = 0;
	for(int i=0;i<n-1;++i) {
		int comum = __gcd(v[i], v[i+1]);
		ans.pb(v[i]);

		if(comum != 1) {
			moves++;
			ans.pb(1);
		}
	}

	cout<<moves<<"\n";
	ans.pb(v[n-1]);	
	for(int &x : ans)
		cout<<x<<" ";
	
}