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

	ll l, r;
	int qnt = 0;
	cin>>l>>r;
	for(ll i=0;;++i) {
		if(l*(1LL<<i) > r) break;
		qnt ++;
	}
	cout<<qnt<<"\n";
}